#include <stdlib.h>

void bar(char *);

void foo() {
  char *P = (char *) malloc (100);
  for (int I = 0; I < 100; ++I)
    P[I] = I;
  bar(P);
  P = (char *) malloc (10);
  for (int I = 0; I < 10; ++I)
    P[I] = I;
  bar(P);
}
