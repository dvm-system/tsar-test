void f() {}

void g() {
# pragma spf transform inline
  f(
#define M 1
  );
}
