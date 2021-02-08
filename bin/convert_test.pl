#!perl
use strict;
use autodie qw(open);
use File::Spec::Functions qw(catfile splitpath);
use File::Path qw(make_path);
use File::Copy;

my $res_dir='converted_tests';

@ARGV or die "usage: convert_test.pl *.conf\n";
my @confs = map glob, @ARGV;

for my $conf (@confs) {
  eval {
    make_test($conf);
  };
  if ($@) {
    warn $@;
  }
}

sub make_test
{
  my $conf = shift;
  (my $name = $conf) =~ s/\.conf$// or die "$conf is not a task.conf\n";

  ## read config file ##
  open my $f, '<', $conf;
  my @lines = <$f>;
  close $f;

  mk_task($name, \@lines, $res_dir);
}

sub mk_task
{
  my ($name, $lines, $res_dir) = @_;

  my @required_vars = qw(options);
  my @uniq_vars = (@required_vars, qw(name));

  ## parse current task configuration file ##
  my %vars;
  my $qr_vars = join '|', @uniq_vars;
  for (@$lines) {
    chomp;
    next if /^\s*$/;
    if (/^($qr_vars)/) { $vars{$1} = $_ }
    elsif ($_ eq q(plugin = TsarPlugin)) {}
    elsif ($_ eq q(sample = $name.c)) {}
    elsif ($_ eq q(run = "$tsar $sample $options")) {}
    elsif ($_ eq q(run = "$tsar $sample $options | -check-prefix=SAFE")) { goto \&mk_task_safe }
    elsif ($_ eq q(      "$tsar $sample $options -fignore-redundant-memory=strict | -check-prefix=REDUNDANT")){ goto \&mk_task_redundant }
    else {
      die "unexpected content in '$name.conf':\n$_\n"
    }
  }
  exists $vars{$_} or die "$name.conf: '$_' is not set\n" for @required_vars;

  my $tdir = catfile($res_dir, $name);
  copy_src($tdir, {"$name.c" => 'main.c'});
  gen_task(catfile($tdir, 'tsar.conf'), @vars{qw(name options)});
}

sub mk_task_safe
{
  my ($name, $lines, $res_dir) = @_;

  my @required_vars = qw(options);
  my @uniq_vars = (@required_vars, qw(name));

  ## parse current task configuration file ##
  my %vars;
  my $qr_vars = join '|', @uniq_vars;
  my @run;
  for (@$lines) {
    chomp;
    next if /^\s*$/;
    if (/^($qr_vars)/) { $vars{$1} = $_ }
    elsif ($_ eq q(plugin = TsarPlugin)) {}
    elsif ($_ eq q(sample = $name.c)) {}
    elsif (/^(?:\s*run\s*=)?\s*\"\$tsar \$sample \$options( [^|]*?)\s*\| -check-prefix=(\S+)\s*"$/) {
      push @run, {
        name_suffix => "-$2",
        run => q(run = "$tsar $sample $options"),
        add_opts => $1 ? " $1" : '',
      }
    }
    else {
      die "unexpected content in '$name.conf':\n$_\n"
    }
  }
  exists $vars{$_} or die "$name.conf: '$_' is not set\n" for @required_vars;

  (my $src_name = $name) =~ s/\.safe$// or die "unexpeced name '$name' for the SAFE test";
  for (@run) {
    my $tdir = catfile($res_dir, $name.$_->{name_suffix});
    copy_src($tdir, {"$src_name.c" => 'main.c'});
    gen_task(catfile($tdir, 'tsar.conf'), $vars{name}, $vars{options}.$_->{add_opts});
  }
}

sub mk_task_redundant
{
  my ($name, $lines, $res_dir) = @_;

  my @required_vars = qw(options);
  my @uniq_vars = (@required_vars, qw(name));

  ## parse current task configuration file ##
  my %vars;
  my $qr_vars = join '|', @uniq_vars;
  my @run;
  for (@$lines) {
    chomp;
    next if /^\s*$/;
    if (/^($qr_vars)/) { $vars{$1} = $_ }
    elsif ($_ eq q(plugin = TsarPlugin)) {}
    elsif ($_ eq q(sample = $name.c)) {}
    elsif ($_ eq q(run = "$tsar $sample $options")) {push @run, {name_suffix => '', run => $_, add_opts => ''}}
    elsif (/^\s*\"\$tsar \$sample \$options( [^|]*?)\s*\| -check-prefix=(\S+)\s*"$/) {
      push @run, {
        name_suffix => "-$2",
        run => q(run = "$tsar $sample $options"),
        add_opts => $1,
      }
    }
    else {
      die "unexpected content in '$name.conf':\n$_\n"
    }
  }
  exists $vars{$_} or die "$name.conf: '$_' is not set\n" for @required_vars;

  for (@run) {
    my $tdir = catfile($res_dir, $name.$_->{name_suffix});
    copy_src($tdir, {"$name.c" => 'main.c'});
    gen_task(catfile($tdir, 'tsar.conf'), $vars{name}, $vars{options}.$_->{add_opts});
  }
}

# copy_src($tdir, {'test_name.c' => 'main.c'})
sub copy_src
{
  my ($dir, $src_map) = @_;
  -e or die "$_ does not exist" for keys %$src_map;
  make_path($dir);
  while (my ($src, $dst) = each %$src_map) {
    $dst = catfile($dir, $dst);
    copy($src, $dst) or die "cannot copy file '$src' to '$dst'\n";
  }
}

sub gen_task
{
  my ($conf, $name, $options) = @_;

  ## generate new config files ##
  open my $f, '>', $conf;
  print $f
'plugin = TsarPlugin
'.($name ? $name : '').'
sources = main.c
copy = $sources
sample = $copy output.txt
clean = $sample
'.$options.'
run = "$tsar $sources $options >output.txt 2>&1"
';
  close $f;
}
