int X, Y, N;

void foo(double * restrict A) {
  int *P;
  X = 5; Y = 6;
  for (int I = 1; I < N - 1; ++I) {
    P = &X;
    Y = 5;
    P = &Y;
    A[I] = 1 + *P;
  }
}
