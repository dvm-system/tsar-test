#include <stdio.h>

#pragma dvm template[100] distribute[block]
void *dvmh_temp0;

void foo(double *X);

int main() {

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double A[100];
  double C[100];

#pragma dvm region in(A)out(A)
  {
#pragma dvm parallel([I] on A[I])
    for (int I = 0; I < 100; ++I) {
      A[I] = I;
    }
  }
  double S = 0;
#pragma dvm actual(S)
#pragma dvm region in(A, S)out(S)
  {
#pragma dvm parallel([I] on A[I]) reduction(sum(S))
    for (int I = 0; I < 100; ++I) {
      S = S + A[I];
    }
  }
  for (int I = 0; I < 100; ++I)
    C[I] = I;
  for (int I = 0; I < 100; ++I) {
#pragma dvm get_actual(S)
    S = S - C[I];
#pragma dvm actual(S)
  }
#pragma dvm get_actual(S)
  printf("%s\n", S == 0 ? "success" : "error");
  return 0;
}