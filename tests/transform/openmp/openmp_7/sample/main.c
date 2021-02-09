typedef int T[10];

void foo(T *A) {
  for (int I = 0; I < 10; ++I)
    for (int J = 0; J < 10; ++J)
      A[I][J] = 0;
}
