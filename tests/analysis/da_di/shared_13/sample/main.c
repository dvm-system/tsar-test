int IStart, IEnd, JStart, JEnd;

void bar();

void foo(double (* restrict U)[100]) {
  int I, J;
  for (int I = IStart; I < IEnd; ++I) {
    ++JStart;
    // JStart is not invariant for outer loop.
    // So, analyzer conservatively assumes dependencies for outer loop.
    for (J = JStart; J < JEnd; ++J)
      U[I][J] = U[I][J] + 1;  
  }
}
