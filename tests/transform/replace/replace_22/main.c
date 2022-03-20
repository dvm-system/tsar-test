struct TTy { int A, B; };

struct STy { struct TTy T; };

int bar(struct STy *S) { return S->T.A; }
int baz(struct STy *S, int I) { return S[I].T.B; }

int foo(struct STy *S) {
#pragma spf transform replace(S) nostrict
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum = bar(S) + baz(S, I);
  return Sum;
}