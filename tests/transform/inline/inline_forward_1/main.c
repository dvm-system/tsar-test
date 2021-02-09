int f();

void f1() {
#pragma spf transform inline
  f();
}


int A;

int f(int A) {
  return A;
}
