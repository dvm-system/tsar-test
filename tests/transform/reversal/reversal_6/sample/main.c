int foo(int L, int R, int S) {
  int X = 1;

  for (int I = L; I <= R; I += S) {
    if (I > 100)
      break;
    X = X * I;
  }
  return X;
}