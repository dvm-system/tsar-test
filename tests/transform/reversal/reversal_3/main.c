int foo() {
  int I, X = 1;
#pragma spf transform reverse(I)
  for (I = 0; I <= 100; ++I) {
    X = X * I;
  }
  return X;
}