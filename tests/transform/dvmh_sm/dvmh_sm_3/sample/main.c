enum { N = 100 };

double A[N][N], B[N];

int main() {
  int I, J;
  double S = 0;
#pragma dvm actual(S)
#pragma dvm region in(A, B, I)out(A, B, I) local(J)
  {
#pragma dvm parallel([I][J]) tie(A[I][J])
    for (I = 0; I < N; ++I)
      for (J = 0; J < N; ++J)
        A[I][J] = I * 2.3 * J;
#pragma dvm parallel([I]) tie(A[I][I], B[I])
    for (I = 1; I < N; ++I)
      B[I] = A[I - 1][I - 1];
  }
#pragma dvm get_actual(B)
  B[0] = 1;
#pragma dvm actual(B)
#pragma dvm region in(A, B, I, S)out(I, S) local(J)
  {
#pragma dvm parallel([I][J]) tie(A[I][J], B[J]) reduction(sum(S))
    for (I = 0; I < N; ++I)
      for (J = 0; J < N; ++J)
        S = S + A[I][J] * B[J];
  }
#pragma dvm get_actual(S)
  return S;
}
