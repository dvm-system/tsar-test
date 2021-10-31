
extern double A[100];
extern double B[100];

void foo() {
#pragma dvm region in(A, B)out(A, B)
  {
#pragma dvm parallel([I]) tie(A[I], B[I])
    for (int I = 0; I < 100; ++I) {
      A[I] = I;
      B[I] = I + 1;
    }
  }
}
