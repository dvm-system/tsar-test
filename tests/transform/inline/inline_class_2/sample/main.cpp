class A {
  void f() { X = 5; }
  int X;
};

A f() {
  A A1;
  return A();
}

void g() {
  #pragma spf transform inline
  f();
}
