#include <stdio.h>

int main() {
  double A[100][100];
  double B[100][100];
  double S = 0;
  for (int I = 0; I < 100; ++I)
    for (int J = 0; J < 100; ++J)
      A[I][J] = I + J;
  for (int I = 1; I < 99; ++I)
    for (int J = 1; J < 99; ++J)
      B[I][J] = A[I][J] + A[I - 1][J - 1] + A[I + 1][J + 1];
  for (int I = 1; I < 99; ++I)
    for (int J = 1; J < 99; ++J)
    S = S + B[I][J];
  printf("S = %f\n", S);
  return 0;
}
