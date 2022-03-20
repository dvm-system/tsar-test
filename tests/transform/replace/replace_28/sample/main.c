struct TTy {
  int A, B;
};

struct STy {
  struct TTy T;
};

int foo(struct STy S) {

  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum += S.T.A + (&S)->T.B;
  return Sum;
}

/* Replacement for int foo(struct STy S) */
int foo_spf0(struct TTy S_T0) {
#pragma spf metadata replace(foo({.T = S_T0}))
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum += S_T0.A + S_T0.B;
  return Sum;
}
