int f() { return 4; }

#define MACRO() x + 

void f1() {
  int x;
#pragma spf transform inline
  MACRO() f();
}
