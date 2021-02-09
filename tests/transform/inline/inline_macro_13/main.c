int f() {
  return __LINE__;
}

int f1() {
  #pragma spf transform inline
  return f();
}
