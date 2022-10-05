#include <stdio.h>

int main(int Argc, char **Argv) {
#pragma spf transform removeunreachable
{
  if (Argc > 1) {
    printf("%s\n", "Command line arguments are specified!");
  } else {
    printf("%s\n", "Command line arguments aren't specified!");
  }
  if (Argc > 1)
    printf("%s\n", "Command line arguments are specified!");
  else
    printf("%s\n", "Command line arguments aren't specified!");
  return 0;
}
}
