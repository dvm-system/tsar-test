#define N 100

int boo(int *A) {
  int sum = 0, square_sum = 0, index;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      index = i * N + j;
      sum += A[index];
      A[index] = A[index] * A[index];
      square_sum += A[index];
    }
  }
  return sum * square_sum;
}