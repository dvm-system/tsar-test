double U[100][100];

void foo() {
  int JStart = 0;
  for (int I = 1; I < 99; ++I) {
    ++JStart;
    for (int J = JStart; J < 99; ++J)
      U[I][J] = U[I - 1][J] + 1;
  }
}
