void f() {
  #define M 10
}

void f1() {
  #pragma spf transform inline
  f();
}
