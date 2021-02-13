#include <string.h>

int foo(char *S) {
  int X = 0;
  for (int I = 0; I < 10; ++I)
    X = X + strlen(S);
  return X;
}
