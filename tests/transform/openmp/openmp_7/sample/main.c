typedef int T[10];

void foo(T *A) {
#pragma omp parallel default(shared)
  {
#pragma omp for
    for (int I = 0; I < 10; ++I)
      for (int J = 0; J < 10; ++J)
        A[I][J] = 0;
  }
}
