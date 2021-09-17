#include <stdio.h>

#pragma dvm template[100] distribute[block]
void *dvmh_temp0;

int Start, End, Step;

int main() {

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double A[100];

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double B[100];
  double S = 0;
#pragma dvm actual(S)
  Start = 5;
  End = 100;
#pragma dvm actual(End)
  Step = 1;
#pragma dvm region in(A, B, End)out(A, B)
  {
#pragma dvm parallel([I] on A[I])
    for (int I = Start; I < End; ++I) {
      A[I] = I;
      B[I] = I + 1;
    }
  }
#pragma dvm region in(A, B, End, S)out(S)
  {
#pragma dvm parallel([I] on A[I]) reduction(sum(S))
    for (int I = Start; I < End; ++I)
      S = S + A[I] + B[I];
  }
#pragma dvm get_actual(S)
  printf("S = %f\n", S);
#pragma dvm actual(End)
  return 0;
}
