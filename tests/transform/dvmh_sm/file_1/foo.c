
extern double A[100];
extern double B[100];

void foo() {
  for (int I = 0; I < 100; ++I) {
      A[I] = I;
      B[I] = I + 1;
  }
}
