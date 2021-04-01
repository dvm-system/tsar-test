#define N 100

int main() {
  int A[N], f = 22;
  for (int i = 0; i < N; ++i) {
    A[i] = 0;
  }
  for (int i = 0; i < N - 1; ++i) {
    A[i] = A[i] + f;
    A[i + 1] = A[i + 1] + f;
  }
  return 0;
}