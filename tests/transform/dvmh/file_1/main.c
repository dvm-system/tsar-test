#include <stdio.h>

double A[100];
double B[100];

void foo();

int main() {
  double S = 0;
  foo();
  for (int I = 0; I < 100; ++I)
    S = S + A[I] + B[I];
  printf("S = %f\n", S);
  return 0;
}
