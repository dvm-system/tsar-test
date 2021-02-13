#include <math.h>

void foo(int *S) {
  for (int I = 0; I < 100; ++I)
    S[I] = sqrt(I);
}
