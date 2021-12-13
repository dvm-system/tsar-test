#include <stdio.h>

int main() {  
  int A[1000];
  int J, S;
  for (J = 0; J < 1000; ++J)
    A[J] = J;
  for (int I = 0; I < 5; ++I) {
    for (J = 0; J < 1000; ++J)
      A[J] = A[J] + I;
  }
  S = A[0];
  for (J = 1; J < 1000; ++J)
    S += A[J];
  printf("S = %d\n", S);
  return 0;
}