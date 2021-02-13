double A[10][10][10];

double foo() {
  double S = 0;
  double S1 = 0;
  for (int K = 0; K < 10; ++K) {
    for (int J = 0; J < 10; ++J)
      for (int I = 0; I < 10; ++I)
        if (S > A[I][J][K])
          S = A[I][J][K];
     S1 += S;
  }
  return S + S1;
}
