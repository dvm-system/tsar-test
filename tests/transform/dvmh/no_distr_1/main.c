#include <stdio.h>

void foo(double *X);

int main() {
  double A[100];
  double B[100];
  double C[100];
  for (int I = 0; I < 100; ++I) {
    A[I] = I;
    B[I] = I + 1;
  }
  double S = 0;
  foo(C);
  for (int I = 0; I < 100; ++I) {
    S = S + A[I] + B[I] + C[I];
  }
  printf("S = %f\n", S);
  return 0;
}