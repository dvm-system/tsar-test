struct STy { int X; };

void bar(struct STy *S, int N) {
  for (int I = 0; I < N; ++I)
    S[I].X = I;
}

void baz(struct STy *S1, struct STy *S2, int N) {
  for (int I = 0; I < N; ++I)
    S1[I].X = S1[I].X + S2[I].X;
}

struct STy * foo(struct STy *S1, struct STy *S2, struct STy *S3, int N) {
#pragma spf transform replace(S1, S2, S3) nostrict
  bar(S1, N);
  bar(S2, N);
  baz(S1, S2, N);
  bar(S3, N);
  return S1;
}

