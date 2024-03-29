void baz(int M, int *restrict T, int N, int *restrict A) {
#pragma omp parallel default(shared)
  {
#pragma omp for
    for (int I = 0; I < N; ++I) {
      A[I] = I;
      for (int J = 0; J < M; ++J)
        A[I] = A[I] + T[J];
    }
  }
}

void bar(int M, int *restrict T, int N, int *restrict A) { baz(M, T, N, A); }

void foo(int N, int *A) {
  int TSize = 4;
  int T[4];
  for (int I = 0; I < TSize; ++I)
    T[I] = I;
#pragma spf region
  { bar(TSize, T, N, A); }
}
