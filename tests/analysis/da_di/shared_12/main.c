int JStart;
void bar();

double foo() {
  double U[100];
  int I, J;
  for (int I = 0; I < 100; I = I + 10) {
    // This call may change global variable JStart.
    // So, JStart is not invariant for the outher loop
    // and analysis will fail.
    bar();
    for (J = JStart; J < 10; ++J)
      U[I + J] = U[I + J] + 1;
  }
  return U[50];
}
