int J;
void foo(int N, double * restrict A) {
  for (int I = 0; I < N; ++I) {
    J = N + I;
    A[I] = I + J;
  }
}
