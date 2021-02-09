#define MACRO f(), 5

int f() { return 0; }

void f2(int y, int z) {
}

void f3() {
#pragma spf transform inline
  f2(MACRO);
}
