
int main() {
  int X[10];
  double Y[15];
#pragma spf transform remove_redarray(X[10], Y[15])
  for (int i = 0; i < 10; i++) {
    X[i] = i + 1;
    Y[i] = 2 * i;
    X[i] = X[i] + 2;
  }
}