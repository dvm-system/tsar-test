enum { N = 100 };

int main() {
  int A[N], C[2];
  int I, S1 = 1, S2 = N;
#pragma dvm actual(A, I, S1, S2)
#pragma dvm region in(A, I, S1, S2)out(A, I, S1, S2) local(C)
  {
#pragma dvm parallel([I]) tie(A[I]) private(C)
    for (I = 0; I < N; ++I) {
      C[0] = C[1] = I;
      int B[4];
      for (int J = 0; J < 4; ++J)
        B[J] = J + C[0] * C[1];
      A[I] = B[0] * B[1] + B[2] * B[3];
    }
#pragma dvm parallel([I]) tie(A[I]) reduction(product(S1), product(S2))
    for (I = 0; I < N; ++I) {
      S1 = S1 * A[I];
      S2 = S2 * A[I];
    }
  }
#pragma dvm get_actual(A, I, S1, S2)

  return S1 + S2;
}
