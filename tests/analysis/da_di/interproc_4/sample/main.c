struct S {
  int Y;
};

int foo(int I, struct S *restrict X) {
   return X->Y = I;
}

void bar(int N, struct S *restrict X, float * restrict A) {
  int I;
  for (int I = 0; I < N; ++I)
    A[I] = foo(I, X);
}
