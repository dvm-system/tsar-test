double foo(double *X, int N) {
  double T[3];
  T[0] = N;
  for (int I = 1; I < N - 1; ++I) {
      T[1] = X[I-1];
      T[2] = X[I+1];
      X[I] += T[0] * T[1] + T[2];
    }
  return T[0] * T[1] + T[2];
}
