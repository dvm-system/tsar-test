struct TTy {
  int A, B;
};

struct STy {
  struct TTy T;
};

int baz(struct STy *S, int I) { return S[I].T.B; }

/* Replacement for int baz(struct STy *S, int I) */
int baz_spf0(struct TTy *S_T0, int I) {
#pragma spf metadata replace(baz({[].T = S_T0}, I))
  return S_T0[I].B;
}

int foo(struct STy *S) {

  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum = S[I].T.A + baz(S, I);
  return Sum;
}

/* Replacement for int foo(struct STy *S) */
int foo_spf0(struct TTy *S_T1) {
#pragma spf metadata replace(foo({[].T = S_T1}))
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum = S_T1[I].A + baz_spf0(S_T1, I);
  return Sum;
}