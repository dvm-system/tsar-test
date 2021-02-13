void bar(int I, int *X) {
  *X = I;
}

void foo(int N, int *A) {
  int X;
  for (int I = 0; I < N; ++I) {
    bar(I, &X);
    A[I] = X;
  }
}
