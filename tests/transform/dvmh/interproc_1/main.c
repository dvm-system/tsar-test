#include <stdio.h>

double foo(double (*restrict A)[100], double (*restrict B)[100]);
double bar(double (*B)[100]);

int main() {
  double A[100][100];
  double B[100][100];
  for (int I = 0; I < 100; ++I)
    for (int J = 0; J < 100; ++J)
      A[I][J] = I + J;
  double S = foo(A, B);
  printf("S = %f\n", S);
  return 0;
}

double foo(double (*restrict A)[100], double (*restrict B)[100]) {
  for (int I = 0; I < 100; ++I) {
    B[I][0] = A[I][0] + 1;
    for (int J = 1; J < 100; ++J)
      B[I][J] = B[I][J - 1] + A[I][J];
  }
  return bar(B);
}

double bar(double (*B)[100]) {
  double S = 0;
  for (int I = 0; I < 100; ++I)
    for (int J = 0; J < 100; ++J)
      S = S + B[I][J];
  return S;
}

