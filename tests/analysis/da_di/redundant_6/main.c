int A[10], B[11];
void bar();

void foo(int *restrict Nx) {
  for (int I = 0; I < 10; ++I) {
    int Nx1 = *Nx + 1;
    A[I] = A[I] + 1;
    B[I+1] = B[I] + 1;
  }
  bar();
}
