struct STy { int A, B; };

#define max1(X, Y) X < Y ? X : Y

#define max2 max1(S2->A, S2->B);
#define max4 max1(S4->A, S4->B);

int foo (struct STy *S1, struct STy *S2,
         struct STy *S3, struct STy *S4) {
#pragma spf transform replace(S1, S2, S3, S4) nostrict
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum += max1(S3[I].A, S3[I].B) + max4;
  return max1(S1->A, S1->B) + max2;
}

