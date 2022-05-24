
int main() {
  int X[10];
  double Y[15];

  for (int i = 0; i < 10; i++) {
    X[i] = i + 1;
    Y[i] = 2 * i;
    X[i] = Y[i];
  }
}