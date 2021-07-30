float A[100][100];

void foo() {

  for (int J = 0; J < 100; ++J)
    for (int I = 0; I < 100; ++I) {
      float X = 1.5;
      for (int K = 0; K < 5; ++K)
        A[I][J] = I + J + X * K;
    }
}
