void bar(int *X) { *X = 10; }

void baz();

int foo() {
  int X, S = 1;
  bar(&X);
  for (int I = 0; I < 10; ++I) {
    X = I;
    S = S * X;
  }
  baz();
  return S;
}
