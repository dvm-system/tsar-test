int A[10], B[11];
void bar();

void foo() {
  for (int I = 0; I < 10; ++I) {
    if (I > 10)
      bar();
    A[I] = A[I] + 1;
    B[I+1] = B[I] + 1;
  }
}
