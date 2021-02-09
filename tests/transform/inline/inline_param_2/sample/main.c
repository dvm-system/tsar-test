void f(void (*h)(int), int I) {
#pragma spf transform inline
  h(I);
}

void g(int I) {
#pragma spf transform inline
  f(g, I);
}
