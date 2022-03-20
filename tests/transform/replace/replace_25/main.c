
struct STy { int (*A)[10]; int *B; int C[][10];};

int foo(struct STy *S, int N) {
#pragma spf transform replace(S) nostrict
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    for (int J = 0; J < N; ++J)
      for (int K = 0; K < 10; ++K)
        Sum += S[I].A[J][K] + S[I].B[J] + S[I].C[J][K];
  return Sum;
}

