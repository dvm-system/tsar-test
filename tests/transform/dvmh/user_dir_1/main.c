#include <stdio.h>

void foo(double *X);

int main() {
  double A[100];
  double C[100];
#pragma spf parallel processprivate(C)
  for (int I = 0; I < 100; ++I) {
    A[I] = I;
  }
  double S = 0;
  for (int I = 0; I < 100; ++I) {
    S = S + A[I];
  }
  for (int I = 0; I < 100; ++I)
    C[I] = I;
  for (int I = 0; I < 100; ++I)
    S = S - C[I];
  printf("%s\n", S == 0 ? "success" : "error");
  return 0;
}