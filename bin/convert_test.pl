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
  my $tdir = catfile($res_dir, $name);
  my $src = $name.'.c';
  -e $src or die "$src does not exit\n";
  my $dst_src = catfile($tdir, 'main.c');
  my $dst_tsar = catfile($tdir, 'tsar.conf');
  make_path($tdir);
  copy($src, $dst_src) or die "cannot copy file '$src' to '$dst_src'\n";
  gen_task($conf, $tdir);
}

sub gen_task
{
  my $conf = shift;
  my $tdir = shift;
  my @required_vars = qw(options);
  my @uniq_vars = (@required_vars, qw(name));

  ## parse current task configuration file ##
  open my $f, '<', $conf;
  my @lines = <$f>;
  close $f;
  my %vars;
  my $qr_vars = join '|', @uniq_vars;
  for (@lines) {
    chomp;
    next if /^\s*$/;
    if (/^($qr_vars)/) { $vars{$1} = $_ }
    elsif ($_ eq q(plugin = TsarPlugin)) {  }
    elsif ($_ eq q(sample = $name.c)) {}
    elsif ($_ eq q(run = "$tsar $sample $options")) {}
    else {
      die "unexpected content in '$conf':\n$_\n"
    }
  }
  exists $vars{$_} or die "$conf: '$_' is not set\n" for @required_vars;

  ## generate new config files ##
  undef $f;
  my $new_conf = catfile($tdir, 'tsar.conf');
  open $f, '>', $new_conf;
  print $f
'plugin = TsarPlugin
'.(exists $vars{name} ? $vars{name} : '').'
sources = main.c
copy = $sources
sample = $copy output.txt
clean = $sample
'.$vars{options}.'
run = "$tsar $sources $options >output.txt 2>&1"
';
  close $f;
}
