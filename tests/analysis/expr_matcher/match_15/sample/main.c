enum { N = 100 };

double X[N][N];

void transpose() {
  double tmp;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + i; j < N; ++j) {
      tmp = X[i][j];
      X[i][j] = X[j][i];
      X[j][i] = tmp;
    }
  }
}