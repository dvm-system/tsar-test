#include <stdio.h>

double A[100];
double B[100];

void foo();

int main() {
  double S = 0;
#pragma dvm actual(S)
  foo();
#pragma dvm region in(A, B, S)out(S)
  {
#pragma dvm parallel([I]) tie(A[I], B[I]) reduction(sum(S))
    for (int I = 0; I < 100; ++I)
      S = S + A[I] + B[I];
  }
#pragma dvm get_actual(A, B, S)
  printf("S = %f\n", S);
#pragma dvm actual(A, B)
  return 0;
}
