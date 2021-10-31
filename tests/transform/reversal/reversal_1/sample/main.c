int foo(int L, int R, int S) {
  int X = 1;

  for (int I = L + (R - 1 - (L)) / (S) * (S); I >= L; I -= S) {
    X = X * I;
  }
  return X;
}