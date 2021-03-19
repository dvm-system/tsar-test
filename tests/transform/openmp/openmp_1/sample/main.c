void foo(int N, double *A) {
#pragma omp parallel default(shared)
  {
#pragma omp for
    for (int I = 0; I < N; ++I) {
      A[I] = I;
    }
  }
}
