int main() {
  int a, b, i;

  for (i = 0; i < 1000; i++) {
    #pragma spf transform initialize(a = b)
  }
  return 0;
}