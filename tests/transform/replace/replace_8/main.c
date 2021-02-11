struct STy { int X; };

#define FOO \
int foo(struct STy *S) { \
 _Pragma("spf transform replace(S) nostrict") \
 return S->X; \
}

FOO
