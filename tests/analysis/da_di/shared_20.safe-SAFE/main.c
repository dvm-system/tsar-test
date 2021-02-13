int JStart;

double foo() {
  double U[100];
  int I, J;
  JStart = 0;
  for (int I = 0; I < 100; I = I + 10) {
    // JStart is global, so SCEV could not be built accurately
    // and analysis will fail for outer loop.
    for (J = JStart; J < 10; ++J)
      U[I + J] = U[I + J] + 1;
  }
  return U[50];
}
