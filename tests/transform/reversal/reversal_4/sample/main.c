int foo(int L, int R, int S) {
  int X = 1;

  for (int I = L + (R - 1 - (L)) / (S) * (S); L <= I; I -= S) {
    X = X * I;
  }
  return X;
}