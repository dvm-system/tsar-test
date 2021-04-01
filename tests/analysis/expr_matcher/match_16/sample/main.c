#define N 100

int main() {
  int A[N], B[N];
  for (int i = 0; i < N; ++i) {
    A[i] = i;
    B[i] = A[i] * i + i;
  }
}