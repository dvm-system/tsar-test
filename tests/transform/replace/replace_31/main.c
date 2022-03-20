struct STy { int A, B; };

#define DECL1 struct STy S
#define DECL2 X;

int foo() {
  DECL1, DECL2
#pragma spf transform replace(S) nostrict
  S.A = S.B = X.A = X.B = 5;
  return (S.A + S.B) * (X.A / X.B);
}

