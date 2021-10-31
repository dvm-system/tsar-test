int foo(int L, int R, int S) {
  int X = 1;
#pragma spf transform reverse(I)
  for (int I = L; I <= R; I = I + S + 1) {
    X = X * I;
  }
  return X;
}