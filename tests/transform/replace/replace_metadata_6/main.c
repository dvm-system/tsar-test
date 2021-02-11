struct STy { int X; };

int bar(struct STy *S) { return S->X; }

int foo(int Y) {
#pragma spf metadata replace(bar({.Y=Y}))
  return Y;
}

