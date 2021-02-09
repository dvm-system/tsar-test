#define M 5

int f() {
  return M;
}

#undef M
#define M 6

int f1() {
#pragma spf transform inline
  return f() + M;
}
