struct STy { int X; };

int bar(struct STy *S) { return S->X; }

int foo(int X, int Y) {
#pragma spf metadata replace(bar({.X=X}, Y))
  return X;
}

int baz() {
  struct STy S;
  #pragma spf transform replace with(foo)
  bar(&S);
  return S.X;
}
