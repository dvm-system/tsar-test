
int main() {
  int *X;
#pragma spf transform remove_redarray(X[10])
  for (int i = 0; i < 10; i++) {
    X[i] = i + 1;
  }
}