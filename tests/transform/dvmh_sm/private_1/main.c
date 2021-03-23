enum { N = 100 };

int main() {
  int A[N], C[2];
  int I, S1 = 1, S2 = N;
  for (I = 0; I < N; ++I) {
    C[0] = C[1] = I;
    int B[4];
    for (int J = 0; J < 4; ++J)
      B[J] = J + C[0] * C[1];
    A[I] = B[0] * B[1] + B[2] * B[3];
  }
  for (I = 0; I < N; ++I) {
    S1 = S1 * A[I];
    S2 = S2 * A[I];
  }
  return S1 + S2;
}
