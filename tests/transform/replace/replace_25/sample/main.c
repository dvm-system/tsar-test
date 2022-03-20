
struct STy {
  int (*A)[10];
  int *B;
  int C[][10];
};

int foo(struct STy *S, int N) {

  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    for (int J = 0; J < N; ++J)
      for (int K = 0; K < 10; ++K)
        Sum += S[I].A[J][K] + S[I].B[J] + S[I].C[J][K];
  return Sum;
}

/* Replacement for int foo(struct STy *S, int N) */
int foo_spf0(int (**S_A0)[10], int **S_B0, int (**S_C0)[10], int N) {
#pragma spf metadata replace(foo({[].A = S_A0, [].B = S_B0, [].C = S_C0}, N))
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    for (int J = 0; J < N; ++J)
      for (int K = 0; K < 10; ++K)
        Sum += S_A0[I][J][K] + S_B0[I][J] + S_C0[I][J][K];
  return Sum;
}
