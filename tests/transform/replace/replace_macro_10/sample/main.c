struct STy {
  int A, B;
};

#define max1(X, Y) X < Y ? X : Y

#define max2 max1(S2->A, S2->B);
#define max4 max1(S4->A, S4->B);

int foo(struct STy *S1, struct STy *S2, struct STy *S3, struct STy *S4) {

  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum += max1(S3[I].A, S3[I].B) + max4;
  return max1(S1->A, S1->B) + max2;
}

/* Replacement for int foo(struct STy *S1, struct STy *S2,
         struct STy *S3, struct STy *S4) */
int foo_spf0(int S1_A0, int S1_B0, struct STy *S2, int *S3_A0, int *S3_B0,
             struct STy *S4) {
#pragma spf metadata replace(                                                  \
    foo({.A = S1_A0, .B = S1_B0}, S2, {[].A = S3_A0, [].B = S3_B0}, S4))
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum += max1(S3_A0[I], S3_B0[I]) + max4;
  return max1(S1_A0, S1_B0) + max2;
}
