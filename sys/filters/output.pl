use Cwd;
use File::Spec::Functions;
BEGIN {
  ($s = canonpath(cwd)) =~ s~\\~\\\\~g;
  if($^O eq 'msys') {
    ## change the path '/c/Users/user/path' to 'C:\\Users\\user\\path' ##
    my @d = split /\//, $s;
    shift @d; #< remote the first '/'
    $s = join '\\\\', (uc shift @d).':', @d;
  }
}
s~$s[\\/]~~g;
