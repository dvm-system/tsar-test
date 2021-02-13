int foo() {
  int X, S = 0;
  for(int I = 0; I < 100; ++I) {
    X = I;
    int *Y = &X;
    int Z = X * 5;
    *Y = Z + *Y;
    S = S + X;
  }
  return S;
}
