#define M "b"

char * f() {
  return "a" M
  "c";
}

void f1() {
  #pragma spf transform inline
  f();
}
