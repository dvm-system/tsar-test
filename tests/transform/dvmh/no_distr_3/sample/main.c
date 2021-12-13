#include <stdio.h>

#pragma dvm template[100] distribute[block]
void *dvmh_temp0;

void foo(double *X, int Size) {
  for (int I = 0; I < Size; ++I)
    X[I] = I * 2;
}

int main() {

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double A[100];

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double B[100];
  double C[100];
  double D[100];
#pragma dvm region in(A, B)out(A, B)
  {
#pragma dvm parallel([I] on B[I])
    for (int I = 0; I < 100; ++I) {
      A[I] = I;
      B[I] = I + 1;
    }
  }
  void (*P)(double *, int) = foo;
  P(D, 100);
#pragma dvm actual(C, D)
  double S = 0;
#pragma dvm actual(S)
  foo(C, 100);
#pragma dvm actual(C, D)
#pragma dvm region in(A, B, C, D, S)out(S)
  {
#pragma dvm parallel([I] on B[I]) reduction(sum(S))
    for (int I = 0; I < 100; ++I) {
      S = S + A[I] + B[I] + C[I] + D[I];
    }
  }
#pragma dvm get_actual(S)
  printf("S = %f\n", S);
#pragma dvm actual(C, D)
  return 0;
}