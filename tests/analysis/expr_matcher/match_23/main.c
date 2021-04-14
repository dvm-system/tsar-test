#include <stdlib.h>

int * foo(int N, int M, int K) {
  int (*A)[M][K];
  A = (int (*)[M][K]) malloc(N * sizeof(int[M][K]));
  return (int *)A;
}
