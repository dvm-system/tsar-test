void f() {
  if (1)
    return;
  return;
}

void g() {
  #pragma spf transform inline
  f();
}
