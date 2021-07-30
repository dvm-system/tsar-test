float A[100][100];

void foo() {

  for (int I = 0; I < 100; ++I)
    for (int J = 0; J < I; ++J)
      A[I][J] = I + J + 1.;
}
