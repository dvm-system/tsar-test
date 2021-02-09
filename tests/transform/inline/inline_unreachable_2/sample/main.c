int foo(int *I) { return *I + 1; }

int main() {
  int I = 0, J;
  if (0) {
#pragma spf transform inline
    J = foo(&I);
  }
  return 0;
}
