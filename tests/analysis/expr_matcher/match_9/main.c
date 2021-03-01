struct YTy { int Q; };
struct STy { float X[10]; struct YTy *Y; };

void foo(struct STy *S) {
  S->X[4] = (*(S->Y)).Q;
}

