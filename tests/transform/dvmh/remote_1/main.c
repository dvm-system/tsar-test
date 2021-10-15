#include <stdio.h>

int Start, End, Step;

int main() {
  double A[100];
  double B[100];
  double S = 0;
  Start = 5;
  End = 100;
  Step = 1;
  A[0] = Start;
  A[1] = End;
  for (int I = Start; I < End; ++I)
      A[I] = I;
  for (int I = Start; I < End; ++I)
    B[I] = A[I] + A[0] + A[1];
  for (int I = Start; I < End; ++I)
    S = S + A[I] + B[I] + A[Start];
  printf("S = %f\n", S);
  return 0;
}
