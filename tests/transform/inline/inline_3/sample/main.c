int X;

void f() {
  X = 4;
}

void g() {
  #pragma spf transform inline
  f();
}

int h() {
  int X = 5;
  #pragma spf transform inline
  g();
  return X;
}
