double U[100][100];
int IStart, IEnd, JStart, JEnd;

void foo() {
  int I, J;
  for (int I = IStart; I < IEnd; ++I) {
    ++JStart;
    // JStart is not invariant for outer loop.
    // So, analyzer at this moment conservatively assumes dependencies
    // for outer loop.
    for (J = JStart; J < JEnd; ++J)
      U[I][J] = U[I][J] + 1;
  }
}
