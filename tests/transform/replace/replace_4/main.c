struct UnusedTy {};

void foo(struct UnusedTy *U1, struct UnusedTy *U2) {
#pragma spf transform replace(U1, U2)
}
