double U[100];

void foo() {
  for (int I = 1; I < 100; ++I)
    for (int J = 0; J < 5; ++J)
      U[I] = U[I - 1] + I;
}

