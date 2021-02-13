double A[100][100][100];

void foo() {  
  for (int I = 99; I >= 3; --I)
    for (int J = 97; J >= 0; --J)
      for (int K = 2; K < 100; ++K)
        A[I][J][K] = A[I + 3][J + 2][K - 2] + A[I][J][K - 1];
  for (int I = 3; I < 100; ++I)
    for (int J = 2; J < 100; ++J)
      for (int K = 97; K >= 0; --K)
        A[I][J][K] = A[I - 3][J - 2][K + 2] + A[I - 2][J - 2][K + 2];
}
