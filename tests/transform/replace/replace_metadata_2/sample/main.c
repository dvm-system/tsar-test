int bar(int Y, int Z) { return Y + Z; }

int foo(int X) {
#pragma spf metadata replace(bar(X))
  return X + X;
}

void baz() {
  #pragma spf transform replace with(foo)
  bar(5, 5);
}