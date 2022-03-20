struct STy {
  int A, B;
};

#define DECL1 struct STy S
#define DECL2 X;

int foo() {
  DECL1, DECL2

             S.A = S.B = X.A = X.B = 5;
  return (S.A + S.B) * (X.A / X.B);
}

/* Replacement for int foo() */
int foo_spf0() {
#pragma spf metadata replace(foo())
  DECL1, DECL2 int S_A0;
  int S_B0;
  S_A0 = S_B0 = X.A = X.B = 5;
  return (S_A0 + S_B0) * (X.A / X.B);
}
