int foo(int L, int R, int S) {
  int X = 1;
#pragma spf transform reverse(I)
  for (int I = L; I < R; I += S) {
    X = X * I;
  }
  return X;
}