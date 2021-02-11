struct STy { int X; };

#define _S_ S->X = X

int foo (struct STy *S, int X) {
 #pragma spf transform replace(S) nostrict
 return _S_;
}

