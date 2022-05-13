
int main() {
  int X[10];
#pragma spf transform remove_redarray(X[10])
  for (int i = 0; i < 10; i++) {
    X[2 * i + 3] = i + 1;
  }
}