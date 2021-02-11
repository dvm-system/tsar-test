struct STy { int X; };

#define CALL bar(S);

void bar(struct STy *S) {
  S->X = S->X + 1;
}

int foo (struct STy *S) {
 #pragma spf transform replace(S) nostrict
 CALL
 return S->X;
}

