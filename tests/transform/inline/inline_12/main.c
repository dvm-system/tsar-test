#include <stdio.h>

void g(int ArgN, char *Val) {
  #pragma spf transform inline
  printf("Arg=%d Val=%s\n", ArgN, Val);
}

int main(int argc, char **argv) {
  #pragma spf transform inline
  g(argc - 1, argv[argc - 1]);
  return 0;
}
