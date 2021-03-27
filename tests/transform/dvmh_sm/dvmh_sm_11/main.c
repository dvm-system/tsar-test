double A[100];

double foo(double K) {
  double S = 0;
  int Res = K > A[50];
  if (Res)
    A[50] = K;
  for (int I = 0; I < 100; ++I)
    S = S * A[I];
  return S;
}
