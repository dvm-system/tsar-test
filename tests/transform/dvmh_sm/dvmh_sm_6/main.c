#include "main.h"

int main() {
  long S = 0;
  for (int I = 0; I < N; ++I)
    for (int J = 0; J < N; ++J)
      for (int K = 0; K < 2; ++K)
        A[I][J][K] = I + J + K;
  for (int I = 1; I < N; ++I)
    for (int J = 1; J < N; ++J)
      for (int K = 0; K < 2; ++K)
        A[I][J][K] = A[I - 1][J][K] + A[I][J - 1][K] + A[I][J][K];
  for (int I = 0; I < N; ++I)
    for (int J = 0; J < N; ++J)
      for (int K = 0; K < 2; ++K)
        S += A[I][J][K];
  printf("Sum = %ld\n", S);
  return 0;
}
