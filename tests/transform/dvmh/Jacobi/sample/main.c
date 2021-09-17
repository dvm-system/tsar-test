//===--- Jacobi.c --------- Jacobi Iterative Method ---------------*- C -*-===//
//
// This file implements Jacobi iterative method which is an iterative method
// used to solve partial differential equations.
//
//===----------------------------------------------------------------------===//

#include <math.h>
#include <stdio.h>

#define Max(A, B) ((A) > (B) ? (A) : (B))

#define L 8
#define ITMAX 10
#define MAXEPS 0.5

#pragma dvm template[8][8] distribute[block][block]
void *dvmh_temp0;

#pragma dvm array align([iEX1][iEX2] with dvmh_temp0[iEX1][iEX2])
double A[L][L];
#pragma dvm array align([iEX1][iEX2] with dvmh_temp0[iEX1][iEX2]) shadow[0][0]
double B[L][L];

int main() {
#pragma dvm region in(A, B)out(A, B)
  {
#pragma dvm parallel([I][J] on A[I][J])
    for (int I = 0; I < L; ++I)
      for (int J = 0; J < L; ++J) {
        A[I][J] = 0;
        if (I == 0 || J == 0 || I == L - 1 || J == L - 1)
          B[I][J] = 0;
        else
          B[I][J] = 3 + I + J;
      }
  }
  for (int It = 1; It <= ITMAX; ++It) {
    double Eps = 0;
#pragma dvm actual(Eps)
#pragma dvm region in(A, B, Eps)out(A, Eps)
    {
#pragma dvm parallel([I][J] on A[I][J]) reduction(max(Eps))
      for (int I = 1; I < L - 1; ++I)
        for (int J = 1; J < L - 1; ++J) {
          double Tmp = fabs(B[I][J] - A[I][J]);
          Eps = Max(Tmp, Eps);
          A[I][J] = B[I][J];
        }
    }
#pragma dvm region in(A, B)out(B)
    {
#pragma dvm parallel([I][J] on B[I][J]) shadow_renew(A [1:1] [1:1])
      for (int I = 1; I < L - 1; ++I)
        for (int J = 1; J < L - 1; ++J)
          B[I][J] =
              (A[I - 1][J] + A[I][J - 1] + A[I][J + 1] + A[I + 1][J]) / 4.0;
    }
#pragma dvm get_actual(Eps)
    double E1 = Eps;
#pragma dvm get_actual(Eps)
#pragma dvm get_actual(A, B)
    printf("It=%4i   Eps=%e\n", It, Eps);
#pragma dvm actual(A, B)
    if (E1 < MAXEPS)
      break;
  }
  return 0;
}
