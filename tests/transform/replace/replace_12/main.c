struct STy { int X; };
struct UnusedTy {};

void foo(struct STy *S, struct UnusedTy *U) {
#pragma spf transform replace(U)
  S->X = 5;
}
