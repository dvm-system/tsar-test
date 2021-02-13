enum { N = 100 };

double A[N];

int main() {
  int I, J;
  double S = 0;
  for (I = 0; I < N; ++I)
    A[I] = I;
  J = 1;
  for (I = 0; I < N - 1; ++I) {
    S = S + A[I] + A[J];
    J = J + 1;
  } 
  return S;
}
