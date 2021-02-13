int IStart, IEnd, JStart, JEnd;

void bar();

void foo(double *U) {
  int I, J;
  for (int I = IStart; I < IEnd; ++I) {
    // If U alias JStart then JStart is not invariant for outer loop.
    // So, at this moment analyzer conservatively assumes dependencies
    // for inner loop.
    for (J = JStart; J < JEnd; ++J)
      U[J + I] = U[J + I] + 1;
  }
}
