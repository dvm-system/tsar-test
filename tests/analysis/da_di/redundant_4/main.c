int A[10], B[11];
int * bar();

void foo() {
  for (int I = 0; I < 10; ++I) {
    int *X;
    if (I > 10)
      X = bar();
    A[I] = A[I] + 1;
    B[I+1] = B[I] + 1;
    if (I > 10)
      X[0] = I;
  }
}
