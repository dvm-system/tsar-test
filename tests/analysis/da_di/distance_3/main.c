double U[100][100];

void foo() {
  for (int I = 1; I < 100; ++I)
    for (int J = 0; J < 99; ++J)
      U[I][J] = U[I - 1][J];
}
