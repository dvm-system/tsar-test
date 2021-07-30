float A[50][100];

void foo() {

  for (int I = 0; I < 50; ++I)
    for (int J = 0; J < 100; J += I + 1)
      A[I][J] = I + J + 1.;
}
