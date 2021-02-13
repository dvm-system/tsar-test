int foo(int I) {
  int X = I;
  while (I < 10) {
    X = I;
    ++I;
  };
  X = X + 1;
  return X;
}
