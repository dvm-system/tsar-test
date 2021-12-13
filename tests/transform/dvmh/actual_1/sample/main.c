#include <stdio.h>

#pragma dvm template[1000] distribute[block]
void *dvmh_temp0;

int main() {

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  int A[1000];
  int I, J, S;
#pragma dvm region in(A, J)out(A, J)
  {
#pragma dvm parallel([J] on A[J])
    for (J = 0; J < 1000; ++J)
      A[J] = J;
  }
  for (I = 0; I < 5; ++I) {
#pragma dvm actual(I)
#pragma dvm region in(A, I, J)out(A, J)
    {
#pragma dvm parallel([J] on A[J])
      for (J = 0; J < 1000; ++J)
        A[J] = A[J] + I;
    }
  }
#pragma dvm actual(I)
#pragma dvm get_actual(A, S)
#pragma dvm remote_access(A[])
  {
    S = A[0];
#pragma dvm actual(S)
  }
#pragma dvm region in(A, J, S)out(J, S)
  {
#pragma dvm parallel([J] on A[J]) reduction(sum(S))
    for (J = 1; J < 1000; ++J)
      S += A[J];
  }
#pragma dvm get_actual(S)
  printf("S = %d\n", S);
  return 0;
}