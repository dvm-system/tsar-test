int foo() {
  int I, X = 1;

  for (I = 100; I >= 0; --I) {
    X = X * I;
  }
  return X;
}