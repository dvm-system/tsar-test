#include <stdio.h>

#pragma dvm template[100][100] distribute[block][block]
void *dvmh_temp0;

int main() {

#pragma dvm array align([iEX1][iEX2] with dvmh_temp0[iEX1][iEX2])
  double A[100][100];

#pragma dvm array align([iEX1][iEX2] with dvmh_temp0[iEX1][iEX2]) shadow[0][0]
  double B[100][100];
  double S = 0;
#pragma dvm actual(S)
#pragma dvm region in(A)out(A)
  {
#pragma dvm parallel([I][J] on A[I][J])
    for (int I = 0; I < 100; ++I)
      for (int J = 0; J < 100; ++J)
        A[I][J] = I + J;
  }
#pragma dvm region in(A, B)out(B)
  {
#pragma dvm parallel([I][J] on B[I][J]) shadow_renew(A [1:1][1:1](corner))
    for (int I = 1; I < 99; ++I)
      for (int J = 1; J < 99; ++J)
        B[I][J] = A[I][J] + A[I - 1][J - 1] + A[I + 1][J + 1];
  }
#pragma dvm region in(B, S)out(S)
  {
#pragma dvm parallel([I][J] on B[I][J]) reduction(sum(S))
    for (int I = 1; I < 99; ++I)
      for (int J = 1; J < 99; ++J)
        S = S + B[I][J];
  }
#pragma dvm get_actual(S)
  printf("S = %f\n", S);
  return 0;
}
