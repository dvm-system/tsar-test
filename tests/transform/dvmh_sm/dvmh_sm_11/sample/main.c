double A[100];

double foo(double K) {
#pragma dvm actual(A)
  double S = 0;
#pragma dvm actual(S)
  int Res = K > A[50];
  if (Res) {
    A[50] = K;
#pragma dvm actual(A)
  }
#pragma dvm region in(A, S)out(S)
  {
#pragma dvm parallel([I]) tie(A[I]) reduction(product(S))
    for (int I = 0; I < 100; ++I)
      S = S * A[I];
  }
#pragma dvm get_actual(S)
  return S;
}
