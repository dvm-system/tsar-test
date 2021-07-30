float A[100][100];

void bar(float *A);

void foo() {
#pragma spf transform interchange(I, J) nostrict
  for (int I = 0; I < 100; ++I)
    for (int J = I; J < 100; ++J)
      bar(&A[I][J]);
}
