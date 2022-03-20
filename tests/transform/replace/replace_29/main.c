struct STy { int A, B; };

int foo() {
  struct STy S1, S2;
  struct STy S3, S4 = {1, 2};
#pragma spf transform replace(S1, S2, S3, S4)
  S1.A = S1.B = S3.A = S3.B = 5; 
  return S1.A + S1.B + S3.A + S3.B + S4.A + S4.B;
}

