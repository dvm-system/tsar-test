float A[100][50][5];

void foo() {
#pragma spf transform interchange(I, J) interchange(J, K)
  for (int I = 0; I < 100; ++I)
    for (int J = 0; J < 50; ++J)
      for (int K = 0; K < 5; ++K)
        A[I][J][K] = I + J + K + 1.;
}
