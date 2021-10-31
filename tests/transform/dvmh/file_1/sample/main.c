#include <stdio.h>

#pragma dvm template[100] distribute[block]
void *dvmh_temp0;

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
double A[100];
#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
double B[100];

void foo();

int main() {
  double S = 0;
#pragma dvm actual(S)
  foo();
#pragma dvm region in(A, B, S)out(S)
  {
#pragma dvm parallel([I] on A[I]) reduction(sum(S))
    for (int I = 0; I < 100; ++I)
      S = S + A[I] + B[I];
  }
#pragma dvm get_actual(S)
#pragma dvm get_actual(A, B)
  printf("S = %f\n", S);
#pragma dvm actual(A, B)
  return 0;
}
