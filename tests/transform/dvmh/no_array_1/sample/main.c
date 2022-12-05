#include <stdio.h>

#pragma dvm template[99] distribute[block]
void *dvmh_temp0;

int main() {
  int X = 0;
#pragma dvm actual(X)
#pragma dvm region in(X)out(X)
  {
#pragma dvm parallel([I] on dvmh_temp0[I]) reduction(product(X))
    for (int I = 0; I < 100; ++I)
      X = X * I;
  }
#pragma dvm get_actual(X)
  printf("X = %d\n", X);
  return 0;
}
