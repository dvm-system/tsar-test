int IStart, IEnd, JStart, JEnd;

void foo(double (*U)[100]) {
  int I, J;
  for (int I = IStart; I < IEnd; ++I) {
    // U may alias JStart and analyzer assumes dependencies for outer loop.
    for (J = JStart; J < JEnd; ++J)
      U[I][J] = U[I][J] + 1;  
  }
}
