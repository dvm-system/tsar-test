float A[100][100];

void foo() {

  for (int J = 0; J < 100; ++J)
    for (int I = 0; I < 100; ++I)
      A[I][J] = I + J + 1.;
}
