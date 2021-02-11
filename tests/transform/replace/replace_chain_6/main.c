struct STy {
  float *X;
  int N;
};

void baz(struct STy *S);

void foo(struct STy *S, int I) {
  if (I < S->N)
    foo(S, I + 1);
  S->X[I] = I;
}           

void bar(struct STy *S1, struct STy *S2) {
#pragma spf transform replace(S1) nostrict
  foo(S1, 0);
  foo(S2, 0);
  baz(S1);
#pragma spf transform replace(S2)
}
