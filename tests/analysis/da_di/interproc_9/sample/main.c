void foo(int *X, int *Y, int Z) {
   for (int K = 0; K < 10; ++K)
     *X = *X + *Y + Z;
}

void bar(int *A) {
  for (int I = 0; I < 100; ++I) {
    int X = I;
    foo(&A[I], &I, X);
  }
}
