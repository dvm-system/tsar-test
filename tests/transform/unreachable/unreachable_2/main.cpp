#include <stdio.h>

int main(int Argc, char **Argv) {
#pragma spf transform removeunreachable
{
  if (int X = Argc; X > 1) {
    printf("%d command line arguments are specified!\n", X);
  } else {
    printf("%s\n", "Command line arguments aren't specified!");
  }
  if (int X = Argc - 1) {
    printf("%d command line arguments are specified!\n", X);
  } else {
    printf("%s\n", "Command line arguments aren't specified!");
  }
  return 0;
}
}
