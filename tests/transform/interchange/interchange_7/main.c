float A[100][100];

void foo() {
  int K = 1;
#pragma spf transform interchange(I, J)
  for (int I = 0; I < 100; ++I)
    for (int J = 0; J < 100; ++J, ++K)
      A[I][J] = K;
}
