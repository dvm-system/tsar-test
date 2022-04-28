int main() {
  int a, b, c, i;

  for (i = 0; i < 1000; i++) {
    #pragma spf transform initialize(a = b, c = 10)
  }
  return 0;
}