#define ARRAY A

void f() {
  int ARRAY[10];
}

void f1() {
#pragma spf transform inline
  f();
}
