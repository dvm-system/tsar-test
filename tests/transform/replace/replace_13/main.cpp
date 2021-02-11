struct UnusedTy {};

struct STy { 
  typedef int Int;
  Int X;
};

void foo(struct STy *S, struct UnusedTy *U) {
#pragma spf transform replace(S, U)
  S->X = 5;
}
