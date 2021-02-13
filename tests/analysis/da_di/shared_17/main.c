int IStart, IEnd, JStart, JEnd;

void foo(double (* restrict U)[100]) {
  int I, J;
  for (int I = IStart; I < IEnd; ++I) {
    for (J = JStart; J < JEnd; ++J)
      U[I][J] = U[I][J] + 1;  
  }
}
