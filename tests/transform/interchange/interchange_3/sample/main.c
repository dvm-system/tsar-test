float A[100][100];

void foo() {
  int I = 0;

  for (; I < 100; ++I)
    for (int J = 0; J < 100; ++J)
      A[I][J] = I + J + 1.;
}
