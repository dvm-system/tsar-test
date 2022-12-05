#include <stdio.h>

int main() {
  int X = 0;
  for (int I = 0; I < 100; ++I)
    X = X * I;
  printf("X = %d\n", X);
  return 0;
}
