int A[100];

int foo();

int main() {
  double S = 0;
#pragma dvm actual(S)
#pragma dvm region in(A)out(A)
  {
#pragma dvm parallel([I]) tie(A[I])
    for (int I = 0; I < 100; ++I)
      A[I] = I;
  }
#pragma dvm get_actual(A)
  int Cond = foo() > A[50];
#pragma dvm actual(A)
  if (Cond) {
#pragma dvm get_actual(A)
    A[50] = foo();
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
