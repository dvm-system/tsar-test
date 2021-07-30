float A[100][50][5];

void foo() {

  for (int K = 0; K < 5; ++K)
    for (int I = 0; I < 100; ++I)
      for (int J = 0; J < 50; ++J)
        A[I][J][K] = I + J + K + 1.;
}
