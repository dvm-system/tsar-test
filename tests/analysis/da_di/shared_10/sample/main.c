double U[100][100];
int IStart, IEnd, JStart, JEnd;

void foo() {
  for (int I = IStart; I < IEnd; ++I)
    for (int J = JStart; J < JEnd; ++J)
      U[I][J] = U[I][J] + 1;
}
