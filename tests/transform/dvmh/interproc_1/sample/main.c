#include <stdio.h>

#pragma dvm template[100][100] distribute[block][block]
void *dvmh_temp0;
#pragma dvm template[100][100] distribute[block][]
void *dvmh_temp0_r0;

#pragma dvm inherit(A, B)
double foo(double (*restrict A)[100], double (*restrict B)[100]);
#pragma dvm inherit(B)
double bar(double (*B)[100]);

int main() {

#pragma dvm array align([iEX1][iEX2] with dvmh_temp0[iEX1][iEX2]) shadow[0][0]
  double A[100][100];

#pragma dvm array align([iEX1][iEX2] with dvmh_temp0[iEX1][iEX2]) shadow[0][0]
  double B[100][100];
#pragma dvm region in(A)out(A)
  {
#pragma dvm parallel([I][J] on A[I][J])
    for (int I = 0; I < 100; ++I)
      for (int J = 0; J < 100; ++J)
        A[I][J] = I + J;
  }
#pragma dvm get_actual(A)
  double S = foo(A, B);
#pragma dvm actual(A)
  printf("S = %f\n", S);
  return 0;
}

#pragma dvm inherit(A, B)
double foo(double (*restrict A)[100], double (*restrict B)[100]) {
#pragma dvm realign(A[iEX0][iEX1] with dvmh_temp0_r0[iEX0][iEX1])
#pragma dvm realign(B[iEX0][iEX1] with dvmh_temp0_r0[iEX0][iEX1])
#pragma dvm parallel([I] on B[I][])
  for (int I = 0; I < 100; ++I) {
    B[I][0] = A[I][0] + 1;
    for (int J = 1; J < 100; ++J)
      B[I][J] = B[I][J - 1] + A[I][J];
  }
#pragma dvm realign(A[iEX0][iEX1] with dvmh_temp0[iEX0][iEX1])
#pragma dvm realign(B[iEX0][iEX1] with dvmh_temp0[iEX0][iEX1])
  return bar(B);
}

#pragma dvm inherit(B)
double bar(double (*B)[100]) {
  double S = 0;
#pragma dvm parallel([I][J] on B[I][J]) reduction(sum(S))
  for (int I = 0; I < 100; ++I)
    for (int J = 0; J < 100; ++J)
      S = S + B[I][J];
  return S;
}
