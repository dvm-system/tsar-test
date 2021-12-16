enum { N = 100 };

int main() {
  int A[N];
  int I, S1 = 1, S2 = N;
#pragma dvm actual(S1, S2)
#pragma dvm region in(A, I, S1, S2)out(A, I, S1, S2)
  {
#pragma dvm parallel([I]) tie(A[I])
    for (I = 0; I < N; ++I)
      A[I] = I;
#pragma dvm parallel([I]) tie(A[I]) reduction(product(S1), product(S2))
    for (I = 0; I < N; ++I) {
      S1 = S1 * A[I];
      S2 = S2 * A[I];
    }
  }
#pragma dvm get_actual(S1, S2)
  return S1 + S2;
}
