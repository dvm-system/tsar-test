struct STy { int X; };
struct UnusedTy {};

void foo(struct STy *S, struct UnusedTy *U) {
#pragma spf transform replace(S, U)
  S->X = 5;
}
