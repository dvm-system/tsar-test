struct TTy {
  int A, B;
};

struct STy {
  struct TTy T;
};

int bar(struct STy *S) { return S->T.A; }

/* Replacement for int bar(struct STy *S) */
int bar_spf0(struct TTy *S_T0) {
#pragma spf metadata replace(bar({.T = S_T0}))
  return (*S_T0).A;
}
int baz(struct STy *S, int I) { return S[I].T.B; }

/* Replacement for int baz(struct STy *S, int I) */
int baz_spf0(struct TTy *S_T1, int I) {
#pragma spf metadata replace(baz({[].T = S_T1}, I))
  return S_T1[I].B;
}

int foo(struct STy *S) {

  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum = bar(S) + baz(S, I);
  return Sum;
}

/* Replacement for int foo(struct STy *S) */
int foo_spf0(struct TTy *S_T2) {
#pragma spf metadata replace(foo({[].T = S_T2}))
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum = bar_spf0(S_T2) + baz_spf0(S_T2, I);
  return Sum;
}