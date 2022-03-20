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

struct STy *foo(struct STy *S1, struct STy *S2, int N) {

  bar(S1, N);
  bar(S2, N);
  return S1;
}

/* Replacement for struct STy * foo(struct STy *S1, struct STy *S2, int N) */
struct STy *foo_spf0(struct STy *S1, int *S2_X0, int N) {
#pragma spf metadata replace(foo(S1, {[].X = S2_X0}, N))
  bar(S1, N);
  bar_spf0(S2_X0, N);
  return S1;
}
