void foo(int N, double *A) {
  int J;
  for (int I = 0; I < N; ++I) {
    J = N +I;
    A[I] = I + J;
  }
}
