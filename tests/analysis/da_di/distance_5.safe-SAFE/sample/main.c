double foo(int JStart) {
  double U[100];
  int I, J;
  JStart = 1;
  for (int I = 0; I < 100; I = I + 10)
    for (J = JStart; J < 10; ++J)
      U[I + J] = U[I + J - 1] + 1;
  return U[50];
}
