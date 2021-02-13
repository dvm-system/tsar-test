enum { N = 100 };

double A[N];
void foo() {
  for (int I = 1; I <= N; ++I) {
    A[N - I] = I;
  }
}
