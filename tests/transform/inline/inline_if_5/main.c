int f() { return 1; }

int g(int X) {
#pragma spf transform inline
  if (X && f())
    return X;
  return 0;
}
