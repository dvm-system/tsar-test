int f() { return 0;}

#define MACRO x+x;

void f2() {
  int x;
#pragma spf transform inline
  MACRO f();
}
