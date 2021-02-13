int foo(int * restrict X) {
   return *X + 1;
}

void bar(int X, int N, float * restrict A) {
  int I;
  for (int I = 0; I < N; ++I)
    A[I] = foo(&X);
}
