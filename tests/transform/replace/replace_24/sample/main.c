struct STy {
  int A[10];
};

int foo(struct STy *S) {

  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    for (int J = 0; J < 10; ++J)
      Sum += S[I].A[J];
  return Sum;
}

/* Replacement for int foo(struct STy *S) */
int foo_spf0(int (*S_A0)[10]) {
#pragma spf metadata replace(foo({[].A = S_A0}))
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    for (int J = 0; J < 10; ++J)
      Sum += S_A0[I][J];
  return Sum;
}