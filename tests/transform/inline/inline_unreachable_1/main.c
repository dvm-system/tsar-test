int foo(int *I) { return *I + 1; }
int main() {
  goto L;
#pragma spf transform inline
{
  int I = 0, J;
  J = foo(&I);
}
L: return 0;
}
