#include <stdio.h>

void foo(double *X, int Size) {
 for (int I = 0; I < Size; ++I)
   X[I] = I * 2;
}

int main() {
  double A[100];
  double B[100];
  double C[200];
  for (int I = 0; I < 100; ++I) {
    A[I] = I;
    B[I] = I + 1;
  }
  double S = 0;
  double *X = C + 100;
  foo(X, 100);
  for (int I = 0; I < 100; ++I) {
    S = S + A[I] + B[I] + C[I + 100];
  }
  printf("S = %f\n", S);
  return 0;
}