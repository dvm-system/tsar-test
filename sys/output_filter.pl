use Cwd;
use File::Spec::Functions;
(my $s = canonpath(cwd)) =~ s~\\~\\\\~g;
s~$s[\\/]~~g;
