#define M

void f() {
  M;
}

void f1() {
  #pragma spf transform inline
  f();
}
