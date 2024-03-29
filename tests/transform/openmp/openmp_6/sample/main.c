double foo(int N, double *restrict A) {
  double S = 0;
#pragma omp parallel default(shared)
  {
#pragma omp for reduction(+ : S)
    for (int I = 0; I < N; ++I) {
      S += A[I];
      A[I] = I;
    }
  }

  return S;
}
