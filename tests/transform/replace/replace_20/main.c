struct TTy { int A, B; };

struct STy { struct TTy T; };

int foo(struct STy *S) {
#pragma spf transform replace(S)
  int Sum = 0;
  for (int I = 0; I < 10; ++I)
    Sum = (*S).T.A + (*S).T.B;
  return Sum;
}

