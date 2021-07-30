float A[100][100];

void foo() {
  int I, J;

  for (J = 0; J < 100; ++J)
    for (I = 0; I < 100; ++I)
      A[I][J] = I + J + 1.;
}
