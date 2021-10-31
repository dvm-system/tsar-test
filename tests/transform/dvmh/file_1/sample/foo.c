
#pragma dvm array
extern double A[100];
#pragma dvm array
extern double B[100];

void foo() {
#pragma dvm region in(A, B)out(A, B)
  {
#pragma dvm parallel([I] on A[I])
    for (int I = 0; I < 100; ++I) {
      A[I] = I;
      B[I] = I + 1;
    }
  }
}
