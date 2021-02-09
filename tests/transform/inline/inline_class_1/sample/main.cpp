struct    A {
  void f() { X = 5; }
  int X;
};

struct    A f() {
  A A1;
  return A();
}

void g() {
  #pragma spf transform inline
  f();
}
