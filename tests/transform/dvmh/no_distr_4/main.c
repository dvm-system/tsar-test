#include <stdio.h>

void foo(int Size, double (*X)[Size]) {
 for (int I = 0; I < Size; ++I)
   for (int J = 0; J < Size; ++J)
     X[I][0] = X[I][0] + X[I][J];
}

int main() {
  double A[100];
  double S = 0;
  for (int I = 0; I < 100; ++I)
    A[I] = I;
  for (int I = 0; I < 100; ++I)
    S = S + A[I];
  printf("S = %f\n", S);
  return 0;
}