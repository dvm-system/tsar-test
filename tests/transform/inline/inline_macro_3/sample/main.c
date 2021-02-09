void f() { int X;}

#define MACRO(f_) f_();

void f1() {
#pragma spf transform inline
  MACRO(f)
}
