int JStart;
void bar();

double foo() {
  double U[100];
  for (int I = 1; I < 100; ++I) {
    bar();
    for (int J = JStart; J < 5; ++J)
      U[I] = U[I - 1] + I;
  }
  return U[50];
}

