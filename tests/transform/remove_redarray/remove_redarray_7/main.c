
int main() {
  int X[3];
  double Y[3];
#pragma spf transform remove_redarray(X[3], Y[3])
  for (int i = 0; i < 10; i++) {
    X[i] = i + 1;
    Y[i] = 2 * i;
    X[i] = X[i] + 2;
  }
}