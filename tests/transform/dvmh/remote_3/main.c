#include <stdio.h>

double A[100];

void init() {
  for (int I = 2; I < 100; ++I)
    A[I] = I;
}

void update() {
  for (int I = 2; I < 100; ++I)
    A[I] = A[I] + A[0] + A[1] + A[50];
}

double exec() {
  double S = 0;
  for (int I = 0; I < 100; ++I)
    S = S + A[I];
  return S;
}

int main() {
  A[0] = 100.;
  A[1] = 200.;
  init();
  update();
  double S = exec(); 
  printf("S = %f\n", S);
  return 0;
}
