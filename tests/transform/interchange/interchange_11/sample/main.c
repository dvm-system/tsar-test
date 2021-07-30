float A[100][100];

void foo() {

  for (int I = 0; I < 100; ++I)
    for (int J = I; J < 100; ++J)
      A[I][J] = I + J + 1.;
}
