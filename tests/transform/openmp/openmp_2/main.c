void foo(int N, double *A) {
  int J = N;
  for (int I = 0; I < N; ++I, ++J) {
    A[I] = I + J;
  }
}
