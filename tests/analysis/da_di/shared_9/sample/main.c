int IStart, IEnd, JEnd;

void foo(int N, int JStart, double * restrict * restrict U) {
  for (int I = IStart; I < IEnd; ++I)
    for (int J = JStart; J <  JEnd; ++J)
      U[I][J] = U[I][J] + 1;
}
