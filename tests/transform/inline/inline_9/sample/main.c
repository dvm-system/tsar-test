void f(int *x) {
 *x = *x + 1;
}

int f1(int *x) {
  #pragma spf transform inline
  return *x = 1, f(x), *x;
}
