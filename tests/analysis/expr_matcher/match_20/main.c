#define N 100

int is_prime(int x);
double boo(double x);

void far(double *A) {
  for (int i = 1; i < N - 1; ++i) {
    if (is_prime(i)) {
      A[i + 1] += 1;
      continue;
    }
    A[i] = boo(A[i]);
    if (is_prime(A[i])) {
      A[i + 1] *= 3;
    }
  }
}