#include <stdio.h>

#pragma dvm template[100] distribute[block]
void *dvmh_temp0;

void foo(int Size, double (*X)[Size]) {
  for (int I = 0; I < Size; ++I)
    for (int J = 0; J < Size; ++J)
      X[I][0] = X[I][0] + X[I][J];
}

int main() {

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double A[100];
  double S = 0;
#pragma dvm actual(S)
#pragma dvm region in(A)out(A)
  {
#pragma dvm parallel([I] on A[I])
    for (int I = 0; I < 100; ++I)
      A[I] = I;
  }
#pragma dvm region in(A, S)out(S)
  {
#pragma dvm parallel([I] on A[I]) reduction(sum(S))
    for (int I = 0; I < 100; ++I)
      S = S + A[I];
  }
#pragma dvm get_actual(S)
  printf("S = %f\n", S);
  return 0;
}