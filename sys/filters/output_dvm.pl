use Cwd;
use File::Spec::Functions;
(my $s = canonpath(cwd)) =~ s~\\~\\\\~g;
s~$s[\\/]~~g;
s~\S+(dvm_sys)~$1~g;
$c = $_;
$_ = $p // '';
$p = $c;
END {
  print "$p" if $p ne " \n";
}

