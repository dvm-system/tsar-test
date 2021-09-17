#include <stdio.h>

int Start, End, Step;

int main() {
  double A[100];
  double B[100];
  double S = 0;
  Start = 5;
  End = 100;
  Step = 1;
  for (int I = Start; I < End; ++I) {
      A[I] = I;
      B[I] = I + 1;
  }
  for (int I = Start; I < End; ++I)
    S = S + A[I] + B[I];
  printf("S = %f\n", S);
  return 0;
}
