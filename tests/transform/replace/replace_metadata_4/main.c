struct STy { int X; };

int bar(struct STy *S) { return S->X; }

int foo(int X) {
#pragma spf metadata replace(bar({.=X}))
  return X;
}
