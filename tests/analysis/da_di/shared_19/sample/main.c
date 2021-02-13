double foo() {
  double U[100];
  int I, J;
  for (int I = 0; I < 100; I = I + 10) {
    for (J = 0; J < 10; ++J)
      U[I + J] = U[I + J] + 1;
  }
  return U[50];
}
