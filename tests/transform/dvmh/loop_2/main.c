#include <stdio.h>

int getStart() { return 5; }
int getStep() { return 1; }
int getEnd() { return 95; }

int main() {
  double A[100];
  double B[100];
  double S = 0;
  int Start = getStart();
  int Step = getStep();
  int End = getEnd();
  for (int I = Start; I < End; I += Step) {
      A[I] = I;
      B[I] = I + 1;
  }
  for (int I = Start; I < End; I += Step)
    S = S + A[I] + B[I];
  printf("S = %f\n", S);
  return 0;
}
