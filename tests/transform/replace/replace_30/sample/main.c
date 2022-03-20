struct STy { int A, B; };

struct STy S3;

int foo() {
  struct STy S1 = {1, 2};
#pragma spf transform replace(S1, S3)
  return S1.A + S1.B;
}

