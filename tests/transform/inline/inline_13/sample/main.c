int f(int *X);

int g(int *X) { return (*X = *X + 1); }

int main() {
  int X;
  // It is not possible to inline f() because its body is not available.
  // However, C stanard does not determine order of calls execution inside
  // a single expression. So, it is valid to perform inlining in this case.
#pragma spf transform inline
  return f(&X) + g(&X);
}
