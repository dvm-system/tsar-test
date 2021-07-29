

int main() {
  int A[10];
  int It, S = 0;
  for (int K = 0; K < 10; ++K)
    A[K] = K;
  for (int I = 0; I < 10; ++I) {
    for (int J = 0; J < 10; ++J) {
      for (int K = 0; K < 10; ++K)
        A[K] = A[K] + 1;
    }
  }
  for (int It = 0; It < 10; ++It)
    for (int K = 0; K < 10; ++K) {
      S = S + A[K];
      A[K] = A[K] + 1;
    }
  return S;
}
