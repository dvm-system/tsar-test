#include <stdio.h>

void foo(double *X, int Size) {
 for (int I = 0; I < Size; ++I)
   X[I] = I * 2;
}

int main() {
  double A[100];
  double B[100];
  double C[100];
  double D[100];
  for (int I = 0; I < 100; ++I) {
    A[I] = I;
    B[I] = I + 1;
  }
  void (*P)(double *, int) = foo;
  P(D, 100);
  double S = 0;
  foo(C, 100);
  for (int I = 0; I < 100; ++I) {
    S = S + A[I] + B[I] + C[I] + D[I];
  }
  printf("S = %f\n", S);
  return 0;
}