float A[100][100];

void bar(float *A);

void foo() {

  for (int J = I; J < 100; ++J)
    for (int I = 0; I < 100; ++I)
      bar(&A[I][J]);
}
