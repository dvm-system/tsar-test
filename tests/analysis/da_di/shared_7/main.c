double U[100][100];
int IStart, IEnd, JEnd;

void foo(int JStart) {
  for (int I = IStart; I < IEnd; ++I)
    for (int J = JStart; J < JEnd; ++J)
      U[I][J] = U[I][J] + 1;
}
