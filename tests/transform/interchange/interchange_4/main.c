float A[100][100];

void foo() {
#pragma spf transform interchange(I, J)
  for (int I = 0; I < 100; ++I) {
    float X = 1.;
    for (int J = 0; J < 100; ++J)
      A[I][J] = I + J + X;
  }
}
