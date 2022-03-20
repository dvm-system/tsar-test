struct TTy { int A, B; };

struct STy { struct TTy T; };

int foo(struct STy *S) {
#pragma spf transform replace(S) nostrict
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum = S[I].T.A + S[I].T.B;
  return Sum;
}
