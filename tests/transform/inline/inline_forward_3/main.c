
void f();

void f1() {
  #pragma spf transform inline
  f();
}

struct A {int X;};

struct S {
enum { SIZE = 10 };
};

void f() { int N[SIZE]; }
