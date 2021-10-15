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
#pragma dvm actual(Start)
  End = 100;
#pragma dvm actual(End)
  Step = 1;
#pragma dvm get_actual(A)
  A[0] = Start;
#pragma dvm actual(A)
#pragma dvm get_actual(A)
  A[1] = End;
#pragma dvm actual(A)
#pragma dvm region in(A, End)out(A)
  {
#pragma dvm parallel([I] on A[I])
    for (int I = Start; I < End; ++I)
      A[I] = I;
  }
#pragma dvm region in(A, B, End)out(B)
  {
#pragma dvm parallel([I] on B[I]) remote_access(A[0], A[1])
    for (int I = Start; I < End; ++I)
      B[I] = A[I] + A[0] + A[1];
  }
#pragma dvm region in(A, B, End, S, Start)out(S)
  {
#pragma dvm parallel([I] on A[I]) remote_access(A[]) reduction(sum(S))
    for (int I = Start; I < End; ++I)
      S = S + A[I] + B[I] + A[Start];
  }
#pragma dvm get_actual(S)
  printf("S = %f\n", S);
#pragma dvm actual(End, Start)
  return 0;
}
