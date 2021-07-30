float A[100][100];

void foo(int X) {
  int I, J;

  for (J = 0; J < 100; ++J)
    for (I = 0; I < 100; I += X + 1)
      A[I][J] = I + J + 1.;
}
