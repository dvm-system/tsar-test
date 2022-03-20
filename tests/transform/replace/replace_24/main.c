struct STy { int A[10]; };

int foo(struct STy *S) {
#pragma spf transform replace(S) nostrict
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    for (int J = 0; J < 10; ++J)
      Sum += S[I].A[J];
  return Sum;
}