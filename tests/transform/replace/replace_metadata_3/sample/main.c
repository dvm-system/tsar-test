int bar(int Y) { return Y; }

int foo(int X, int Z) {
#pragma spf metadata replace(bar(X))
  return X + Z;
}
