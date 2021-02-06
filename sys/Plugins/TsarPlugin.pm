package Plugins::TsarPlugin;
use Plugins::Base v0.6.1;
use Plugins::Base::Util;
use base qw(Plugins::Base);
use strict;

use ConfigFile;
use Exceptions;
use File::chdir;
use File::Copy qw(copy);
use File::Path qw(make_path);
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
    platform
    dvm
  )],
);
my $sys_conf;
my $sys_conf_fname = catfile(get_package_dir(), 'config');
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
  $task->set_predefined_var(@$_, $sys_conf->get_arr(@$_)) for (
    (map {my $g=$_; map [$g => $_], @{$required_vars{$_}}} keys %required_vars),
    #['' => 'var'],
  );
  $task->reload_config;

  my $action = $task->get_var('', 'action', 'check');
  my $init  = $action eq 'init'  or
  my $check = $action eq 'check' or
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
  if (my @a = grep file_name_is_absolute($_), @clean) {
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

  ## make work directory ##
  m_chdir($tdir_abs);
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

  ## run the command ##
  m_chdir($work_dir);
  m_system($run);

  ## compare results ##
  m_chdir($tdir_abs);
  my $errors = 0;
  if ($init) {
    for my $fname (@sample) {
      m_copy(catfile($work_dir, $fname), catfile($sample_dir, $fname));
    }
    while (my ($fname, $fname_ref) = %sample_map) {
      $fname_ref = catfile($sample_dir, $fname_ref) if !file_name_is_absolute($fname_ref);
      m_copy(catfile($work_dir, $fname), $fname_ref);
    }
  }
  else {
    for my $fname (@sample) {
      m_compare(catfile($work_dir, $fname), catfile($sample_dir, $fname)) or ++$errors;
    }
    while (my ($fname, $fname_ref) = %sample_map) {
      $fname_ref = catfile($sample_dir, $fname_ref) if !file_name_is_absolute($fname_ref);
      m_compare(catfile($work_dir, $fname), $fname_ref) or ++$errors;
    }
  }

  !$errors
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

1;
