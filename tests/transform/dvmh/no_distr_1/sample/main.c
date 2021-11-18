#include <stdio.h>

#pragma dvm template[100] distribute[block]
void *dvmh_temp0;

void foo(double *X);

int main() {

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double A[100];

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double B[100];
  double C[100];
#pragma dvm region in(A, B)out(A, B)
  {
#pragma dvm parallel([I] on A[I])
    for (int I = 0; I < 100; ++I) {
      A[I] = I;
      B[I] = I + 1;
    }
  }
  double S = 0;
#pragma dvm actual(S)
  foo(C);
#pragma dvm actual(C)
#pragma dvm actual(C)
#pragma dvm region in(A, B, C, S)out(S)
  {
#pragma dvm parallel([I] on A[I]) reduction(sum(S))
    for (int I = 0; I < 100; ++I) {
      S = S + A[I] + B[I] + C[I];
    }
  }
#pragma dvm get_actual(S)
  printf("S = %f\n", S);
#pragma dvm actual(C)
  return 0;
}