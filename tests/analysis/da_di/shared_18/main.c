int IStart, IEnd, JStart, JEnd;

void bar();

void foo(double * restrict U) {
  int I, J;
  for (int I = IStart; I < IEnd; ++I) {
    // U is not alias JStart due to 'restrict' keyword.
    // Hence, JStart is invariant for outer loop and
    // analyzer can prove absence of data dependence in the inner loop.
    for (J = JStart; J < JEnd; ++J)
      U[J + I] = U[J + I] + 1;
  }
}
