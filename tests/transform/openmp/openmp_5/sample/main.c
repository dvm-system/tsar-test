int J;
void foo(int N, double *restrict A) {
#pragma omp parallel default(shared)
  {
#pragma omp for lastprivate(J) firstprivate(J)
    for (int I = 0; I < N; ++I) {
      J = N + I;
      A[I] = I + J;
    }
  }
}
