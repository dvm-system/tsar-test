#include <stdio.h>

int main() {
  double A[100];
  A[0] = 100.;
  A[1] = 200.;
  for (int I = 2; I < 100; ++I)
    A[I] = I;
  for (int I = 2; I < 100; ++I)
    A[I] = A[I] + A[0] + A[1] + A[50];
  double S = 0;
  for (int I = 0; I < 100; ++I)
    S = S + A[I];
  printf("S = %f\n", S);
  return 0;
}
