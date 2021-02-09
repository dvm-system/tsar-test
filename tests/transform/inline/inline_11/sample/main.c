void f(int *X) { *X = 10; }

#define INLINE _Pragma("spf transform inline")

void g() {
  int Y;
  INLINE
  f(&Y);
}
