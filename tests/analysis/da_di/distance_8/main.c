enum { N = 100 };

double A[N][N];

void foo() {
  int I, J;
  for (I = 1; I < N; ++I) {
    for (J = 0; J < N; ++J)
      A[I][J] = A[I][J] + I + J;
    for (J = 1; J < N; ++J)
      A[I][J] = A[I-1][J] + A[I][J-1];
  }
}
