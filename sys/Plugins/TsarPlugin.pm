package Plugins::TsarPlugin;
use Plugins::Base v0.6.1;
use Plugins::Base::Util;
use base qw(Plugins::Base);
use strict;

use ConfigFile;
use Exceptions;
use File::chdir;
use File::Copy qw(copy);
use File::Path qw(make_path remove_tree);
use File::Spec::Functions qw(catfile rel2abs splitpath catpath file_name_is_absolute);
use Text::Diff;

=head1 DESCRIPTION
TSAR (Traits Static AnalyzeR) test plugin for PTS (Process Task Set)
=cut

use constant exe_extension => $^O eq 'MSWin32' ? '.exe' : '';
use constant run_prefix => $^O eq 'MSWin32' ? '' : './';

my %required_vars = (
  '' => [qw(
    tsar
    clang
    include
    dvm
  )],
);
my $sys_conf;
my $sys_dir = get_package_dir();
my $sys_conf_fname = catfile($sys_dir, 'config');
try {
  $sys_conf = ConfigFile->new($sys_conf_fname, required => \%required_vars);
  $sys_conf->load;
}
make_exlist
catch {
  die "TsarPlugin encountered problems with its configuration file '$sys_conf_fname':\n"
    .(join '', map "  $_", @{$@});
};

sub process
{
  my ($class, $task, $db) = @_;

  $task->set_predefined_var('', 'exe_extension', exe_extension);
  $task->set_predefined_var('', 'run_prefix', run_prefix);
  $task->set_predefined_var('', 'platform', ($^O eq 'MSWin32' ? 'win' : 'uni'));
  $task->set_predefined_var('', 'sys_dir', $sys_dir);
  $task->set_predefined_var('', 'perl', $^X);
  $task->set_predefined_var(@$_, $sys_conf->get_arr(@$_)) for (
    (map {my $g=$_; map [$g => $_], @{$required_vars{$_}}} keys %required_vars),
    #['' => 'var'],
  );
  $task->reload_config;

  return 'skipped' if m_skip_not_set($task);

  my $action = $task->get_var('', 'action', 'check');
  my $init  = $action eq 'init'  or
  my $check = $action eq 'check' or
  my $clean = $action eq 'clean' or
  my $show  = $action eq 'show'  or
  die "action=$action is not supported.\n";

  my $run = $task->get_var('', 'run');
  my $work_dir = $task->get_var('', 'work_dir', 'res');
  my $sample_dir = $task->get_var('', 'sample_dir', 'sample');
  my @copy = $task->get_arr('', 'copy', []);
  my @clean = $task->get_arr('', 'clean', []);
  my @sample = $task->get_arr('', 'sample', []);
  my %sample_map = $task->get_arr('', 'sample_map', []);

  my $tdir_abs = rel2abs($task->task_dir);
  local $CWD;

  dbg1 and dprint("tsar=", $task->get_var('', 'tsar', ''));

  ## check variables ##
  if (my @a = grep file_name_is_absolute($_), @copy) {
    die "Variable 'copy' should contain only relative paths. These are absolute:\n"
      .join("\n", map "  $_", @a);
  }
  if (my @a = grep file_name_is_absolute($_), @sample) {
    die "Variable 'sample' should contain only relative paths. These are absolute:\n"
      .join("\n", map "  $_", @a);
  }
  if (my @a = grep file_name_is_absolute($_), keys %sample_map) {
    die "Variable 'sample_map' should contain only relative paths at the left side. These are absolute:\n"
      .join("\n", map "  $_", @a);
  }
  $work_dir eq '' and die "Variable work_dir is set to an empty string.\n";

  ## cd task_dir ##
  m_chdir($tdir_abs);

  if ($clean) {
    -d $work_dir or return 1;
    ## remove specified files ##
    m_chdir($work_dir);
    clean(@clean);
    ## try to remove empty work_dir ##
    m_chdir($tdir_abs);
    m_rm_empty_dir_recursive($work_dir);
    return 1
  }
  elsif ($show) {
    print_out("########## ".$task->fullname." ##########\n");
    for my $fname (@copy) {
      show_file($fname);
    }
    for my $fname (@sample) {
      show_diff(catfile($sample_dir, $fname), catfile($work_dir, $fname));
    }
    while (my ($fname, $fname_ref) = each %sample_map) {
      $fname_ref = catfile($sample_dir, $fname_ref) if !file_name_is_absolute($fname_ref);
      show_diff($fname_ref, catfile($work_dir, $fname));
    }
    return 1
  }

  ## make work directory ##
  if (-e $work_dir) {
    -d $work_dir or die "work_dir='$work_dir' is not a directory.\n";
  }
  else {
    make_path($work_dir);
  }

  ## copy files ##
  for my $fname (@copy) {
    m_copy($fname, catfile($work_dir, $fname));
  }

  ## set environment ##
  local %ENV = %ENV;
  $ENV{$_} = $task->get_var('env', $_) for $task->var_names('env');
  # apply $add_include_path
  if (my @add_inc = $task->get_arr('', 'add_include_path', [])) {
    my $delim = $^O eq 'MSWin32' ? ';' : ':';
    my $path = join $delim, @add_inc;
    $ENV{$_} = $ENV{$_} ? join $delim, $ENV{$_}, $path : $path
      for qw(C_INCLUDE_PATH CPLUS_INCLUDE_PATH);
  }

  ## run the command ##
  m_chdir($work_dir);
  #dbg2 and dprint("environment:\n", map "  $_=$ENV{$_}\n", sort keys %ENV);
  m_system($run);

  ## compare results ##
  m_chdir($tdir_abs);
  my $errors = 0;
  if ($init) {
    for my $fname (@sample) {
      m_copy(catfile($work_dir, $fname), catfile($sample_dir, $fname));
    }
    while (my ($fname, $fname_ref) = each %sample_map) {
      $fname_ref = catfile($sample_dir, $fname_ref) if !file_name_is_absolute($fname_ref);
      m_copy(catfile($work_dir, $fname), $fname_ref);
    }
  }
  else {
    for my $fname (@sample) {
      m_compare(catfile($work_dir, $fname), catfile($sample_dir, $fname)) or ++$errors;
    }
    while (my ($fname, $fname_ref) = each %sample_map) {
      $fname_ref = catfile($sample_dir, $fname_ref) if !file_name_is_absolute($fname_ref);
      m_compare(catfile($work_dir, $fname), $fname_ref) or ++$errors;
    }
  }

  !$errors
}

sub clean
{
  my @files = @_;
  for (map glob, @files) {
    file_name_is_absolute($_) and die "Action 'clean' encountered an absolute filename '$_'.\n";
    -e or next;
    my $err;
    dbg1 and dprint("rm '$_'");
    remove_tree($_, {safe => 1, error => \$err});
    if ($err && @$err) {
      my @errors = map {
        my ($f, $msg) = %$_;
        Exceptions::Exception->new($f eq '' ? "rm '$f' failed: $msg" : $msg);
      } @$err;
      throw List => @errors;
    }
  }
  1
}

sub show_file
{
  my $fname = shift;
  print_out("#### $fname ####\n");
  -e $fname or return;
  open my $f, '<', $fname or die "cannot open file $fname: $!\n";
  if ($fname =~ /\.(?:cpp|c|f|f77)$/) {
    my $i = 0;
    print_out(map sprintf("%3d: $_", ++$i), <$f>);
  }
  else {
    print_out(<$f>);
  }
  close $f;
}

sub show_diff
{
  my ($src, $dst) = @_;
  if (!-e $src || !-e $dst) {
    show_file($src);
    show_file($dst);
    return;
  }
  my $diff = diff($src, $dst) or return;
  print_out("#### $src <=> $dst ####\n");
  print_out($diff);
}

sub m_rm_empty_dir_recursive
{
  my $dir = shift;
  my $d;
  if (!opendir $d, $dir) {
    print_out("cannot read directory '$dir' content\n");
    return 0;
  }
  my @fnames = grep {$_ ne '.' && $_ ne '..'} readdir $d;
  closedir $d;
  my $del = 1;
  for (@fnames) {
    my $fname = catfile($dir, $_);
    next if -d $fname && m_rm_empty_dir_recursive($fname);
    $del = 0;
  }
  if ($del) {
    dbg1 and dprint("rm empty directory '$dir'");
    $del = rmdir $dir or print_out("cannot remove empty directory '$dir': $!\n");
  }
  $del
}

sub m_system
{
  my $cmd = join ' ', @_;
  dbg1 and dprint($cmd);
  dbg1 and dtimer_reset('system');
  system($cmd) == 0 or die "`$cmd` failed\n";
  dbg1 and dprint_t('system', 'done');
}

sub m_copy
{
  dbg1 and dprint("copy '$_[0]' to '$_[1]'");
  my $dir = catpath((splitpath($_[1]))[0,1]);
  -d $dir or make_path($dir);
  copy($_[0], $_[1]) or die "Cannot copy '$_[0]' to '$_[1]': $!\n";
}

sub m_compare
{
  my ($fname, $fname_ref) = @_;
  dbg1 and dprint("compare '$fname' and '$fname_ref'");
  if (!-e $fname) {
    print_out("Result file '$fname' does not exist.\n");
    return 0;
  }
  if (!-e $fname_ref) {
    print_out("Sample file '$fname_ref' does not exist.\n");
    return 0;
  }
  if (diff $fname, $fname_ref) {
    print_out("File '$fname' differs from '$fname_ref'\n");
    return 0;
  }
  1
}

sub m_chdir
{
  $CWD = $_[0] or die "Cannot chdir to '".rel2abs($_[0])."'";
  dbg1 and dprint("CWD = $CWD");
}

sub m_skip_not_set
{
  my $task = shift;

  for ($task->get_arr('skip', 'not_set', [])) {
    my ($gr, $var) = /^(\w*)::(\w+)$/ or die "Variable skip::not_set has a wrong value '$_'."
      ." It should contain a list of variables in the form 'group::var'.\n";
    $gr //= '';
    if (!$task->get_arr($gr, $var, [])) {
      print_out("Variable $_ is not set.\n");
      return 1
    }
  }
  0
}

1;
