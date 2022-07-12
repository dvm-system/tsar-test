enum { N = 100 };

double A[N][N][N];

void foo() {
  int I, J, K;
  for (I = 1; I < N; ++I)
    for (J = 0; J < N; ++J)
      for (K = 0; K < N; ++K)
        A[I][J][K] = A[I][J][K] + A[I-1][J][K];
}
