
struct STy;
void foo(struct STy *S, int I);

void baz(struct STy *S, int I) {
  foo(S, I);
}

typedef float DataT;

struct STy {
  DataT *X;
  int N;
};

void foo(struct STy *S, int I) {
  if (I < S->N)
    foo(S, I + 1);
  S->X[I] = I;
}

void bar(struct STy *S1, struct STy *S2) {
#pragma spf transform replace(S1, S2) nostrict
  baz(S1, 0);
  S2->N = 10;
}
