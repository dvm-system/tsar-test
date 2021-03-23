enum { N = 100 };

int main() {
  int A[N];
  int I, S1 = 1, S2 = N;
  for (I = 0; I < N; ++I)
    A[I] = I;
  for (I = 0; I < N; ++I) {
    S1 = S1 * A[I];
    S2 = S2 * A[I];
  }
  return S1 + S2;
}
