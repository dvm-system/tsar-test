int A[100];

int foo();

int main() {
  double S = 0;
  for (int I = 0; I < 100; ++I)
    A[I] = I;
  int Cond = foo() > A[50];
  if (Cond)
    A[50] = foo();
  for (int I = 0; I < 100; ++I)
    S = S * A[I];
  return S;
}
