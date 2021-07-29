

int main() {
  int A[10];
  int It, S = 0;
#pragma dvm actual(S)
#pragma dvm region in(A)out(A)
  {
#pragma dvm parallel([K]) tie(A[K])
    for (int K = 0; K < 10; ++K)
      A[K] = K;
  }
  for (int I = 0; I < 10; ++I) {
    for (int J = 0; J < 10; ++J) {
#pragma dvm region in(A)out(A)
      {
#pragma dvm parallel([K]) tie(A[K])
        for (int K = 0; K < 10; ++K)
          A[K] = A[K] + 1;
      }
    }
  }
  for (int It = 0; It < 10; ++It) {
#pragma dvm region in(A, S)out(A, S)
    {
#pragma dvm parallel([K]) tie(A[K]) reduction(sum(S))
      for (int K = 0; K < 10; ++K) {
        S = S + A[K];
        A[K] = A[K] + 1;
      }
    }
  }
#pragma dvm get_actual(S)
  return S;
}
