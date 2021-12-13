#include <stdio.h>

#pragma dvm template[100] distribute[block]
void *dvmh_temp0;

int main() {

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double A[100];
#pragma dvm get_actual(A)
  A[0] = 100.;
#pragma dvm actual(A)
#pragma dvm get_actual(A)
  A[1] = 200.;
#pragma dvm actual(A)
#pragma dvm region in(A)out(A)
  {
#pragma dvm parallel([I] on A[I])
    for (int I = 2; I < 100; ++I)
      A[I] = I;
  }
  for (int I = 2; I < 100; ++I) {
#pragma dvm get_actual(A)
#pragma dvm remote_access(A[])
    {
      A[I] = A[I] + A[0] + A[1] + A[50];
#pragma dvm actual(A)
    }
  }
  double S = 0;
#pragma dvm actual(S)
#pragma dvm region in(A, S)out(S)
  {
#pragma dvm parallel([I] on A[I]) reduction(sum(S))
    for (int I = 0; I < 100; ++I)
      S = S + A[I];
  }
#pragma dvm get_actual(S)
  printf("S = %f\n", S);
  return 0;
}
