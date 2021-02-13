void foo(double *X, int N) {
  double T[2];
  for (int I = 1; I < N - 1; ++I) {
    T[0] = X[I-1];
    T[1] = X[I+1];
    X[I] += T[0] + T[1];
  }
}
