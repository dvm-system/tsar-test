int f1() { return 0;}

#define MACRO + x

void f2() {
  int x;
#pragma spf transform inline
  f1() MACRO;
}
