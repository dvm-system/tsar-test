double U[100][100][100][5];
int IStart, IEnd, JStart, JEnd, KStart, KEnd;

void foo() {
  int I, J, K, M;
  for (I = IStart; I < IEnd; ++I)
    for (J = JStart; J < JEnd; ++J)
      for (K = KStart; K < KEnd; ++K)
        for (M = 0; M < 5; ++M)
          U[I][J][K][M] = U[I][J][K][M] + 1;
}
