int A[10], B[11];
int * bar();

void foo() {
  for (int I = 0; I < 10; ++I) {
    if (I > 10)
      bar()[4] = 6;
    A[I] = A[I] + 1;
    B[I+1] = B[I] + 1;
  }
}
