int main() {
  int i;
  int a;

  int foo();

  for (i = 0; i < 1000; i++) {
    #pragma spf transform initialize(foo = a)
  }
  return 0;
}