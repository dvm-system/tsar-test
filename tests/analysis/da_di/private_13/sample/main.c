long long N;

void foo(double * restrict X, int * restrict A) {
  for (int I = 0; I < N; ++I) {
    A[I] = A[I] + 1;
    *(X + N) = A[I];
  }
}
