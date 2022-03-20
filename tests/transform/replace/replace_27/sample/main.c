struct STy {
  int X;
};

void bar(struct STy *S, int N) {
  for (int I = 0; I < N; ++I)
    S[I].X = I;
}

/* Replacement for void bar(struct STy *S, int N) */
void bar_spf0(int *S_X0, int N) {
#pragma spf metadata replace(bar({[].X = S_X0}, N))
  for (int I = 0; I < N; ++I)
    S_X0[I] = I;
}

void baz(struct STy *S1, struct STy *S2, int N) {
  for (int I = 0; I < N; ++I)
    S1[I].X = S1[I].X + S2[I].X;
}

/* Replacement for void baz(struct STy *S1, struct STy *S2, int N) */
void baz_spf0(int *S1_X0, int *S2_X0, int N) {
#pragma spf metadata replace(baz({[].X = S1_X0}, {[].X = S2_X0}, N))
  for (int I = 0; I < N; ++I)
    S1_X0[I] = S1_X0[I] + S2_X0[I];
}

struct STy *foo(struct STy *S1, struct STy *S2, struct STy *S3, int N) {

  bar(S1, N);
  bar(S2, N);
  baz(S1, S2, N);
  bar(S3, N);
  return S1;
}

/* Replacement for struct STy * foo(struct STy *S1, struct STy *S2, struct STy
 * *S3, int N) */
struct STy *foo_spf0(struct STy *S1, struct STy *S2, int *S3_X0, int N) {
#pragma spf metadata replace(foo(S1, S2, {[].X = S3_X0}, N))
  bar(S1, N);
  bar(S2, N);
  baz(S1, S2, N);
  bar_spf0(S3_X0, N);
  return S1;
}
