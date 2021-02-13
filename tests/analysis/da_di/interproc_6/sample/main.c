void foo(int N, double *restrict X, float * restrict A) {
   for (int I = 0; I < 10; ++I) {
     // *X is live after the exit from foo()
     *X = I;
     A[I] = *X;   
   }
}

int bar(int N, float * restrict A) {
  double X = N;
  foo(N, &X, A);
  return X;
}
