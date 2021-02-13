#include <stdlib.h>

void bar(int *);

void foo() {
  int *P = (int *) malloc (100);
  for (int I = 0; I < 100; ++I)
    P[I] = I;
  bar(P);
}
