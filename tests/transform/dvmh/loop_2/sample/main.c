#include <stdio.h>

#pragma dvm template[100] distribute[block]
void *dvmh_temp0;

int getStart() { return 5; }
int getStep() { return 1; }
int getEnd() { return 95; }

int main() {

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double A[100];

#pragma dvm array align([iEX1] with dvmh_temp0[iEX1]) shadow[0]
  double B[100];
  double S = 0;
#pragma dvm actual(S)
  int Start = getStart();
  int Step = getStep();
#pragma dvm actual(Step)
  int End = getEnd();
#pragma dvm actual(End)
#pragma dvm region in(A, B, End, Step)out(A, B)
  {
#pragma dvm parallel([I] on A[I])
    for (int I = Start; I < End; I += Step) {
      A[I] = I;
      B[I] = I + 1;
    }
  }
#pragma dvm region in(A, B, End, S, Step)out(S)
  {
#pragma dvm parallel([I] on A[I]) reduction(sum(S))
    for (int I = Start; I < End; I += Step)
      S = S + A[I] + B[I];
  }
#pragma dvm get_actual(S)
  printf("S = %f\n", S);
  return 0;
}
