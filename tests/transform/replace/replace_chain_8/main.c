struct STy {
  float *X;
  int N;
};

void baz(struct STy *S);

void foo(struct STy *S) { baz(S); }

void bar(struct STy *S) {
#pragma spf transform replace(S)
  foo(S);
}
