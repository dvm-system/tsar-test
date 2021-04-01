#define N 100

double boo(double x);

// A[N], B[N * N]
void far(double *A, double *B) {
  int index;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      index = i * N + j;
      B[index] = boo(B[index]);
    }
    A[i] = B[index];
  }
}