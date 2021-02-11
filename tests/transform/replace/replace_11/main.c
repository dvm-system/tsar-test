struct STy { int X; };
struct DTy { struct STy S; };

#define STy struct STy
int foo(struct DTy *D, int X) {
 _Pragma("spf transform replace(D) nostrict")
 return D->S.X = X;
}

