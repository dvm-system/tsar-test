struct STy {
  int A, B;
};

int foo() {
  struct STy S1, S2;
  struct STy S3, S4 = {1, 2};

  S1.A = S1.B = S3.A = S3.B = 5;
  return S1.A + S1.B + S3.A + S3.B + S4.A + S4.B;
}

/* Replacement for int foo() */
int foo_spf0() {
#pragma spf metadata replace(foo())
  int S1_A0;
  int S1_B0;
  struct STy S3, S4 = {1, 2};
  int S3_A0;
  int S3_B0;
  S1_A0 = S1_B0 = S3_A0 = S3_B0 = 5;
  return S1_A0 + S1_B0 + S3_A0 + S3_B0 + S4.A + S4.B;
}
