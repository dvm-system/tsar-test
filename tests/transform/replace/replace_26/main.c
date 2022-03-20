struct STy { int X; };

void bar(struct STy *S, int N) {
  for (int I = 0; I < N; ++I)
    S[I].X = I;
}

struct STy * foo(struct STy *S1, struct STy *S2, int N) {
#pragma spf transform replace(S1, S2) nostrict
  bar(S1, N);
  bar(S2, N);
  return S1;  
}

