struct STy { int *B; };

int foo(struct STy *S, int N) {  
  int Sum = 0;
  for (int I = 0; I < N; ++I)
    for (int J = 0; J < N; ++J)
        Sum = S[I].B[J];
  return Sum;
}

/* Replacement for int foo(struct STy *S, int N) */
int foo_spf0(int **S_B0, int N) {
#pragma spf metadata replace(foo({[].B = S_B0}, N))
  int Sum = 0;
  for (int I = 0; I < N; ++I)
    for (int J = 0; J < N; ++J)
        Sum = S_B0[I][J];
  return Sum;
}

void bar(struct STy *S1, struct STy *S2, int N) {
#pragma spf transform replace(S1) with(foo_spf0)
  foo(S1, N);
  foo(S2, N);
}
