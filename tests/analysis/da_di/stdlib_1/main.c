#include <string.h>

int foo(char *S) {
  int X = 0;
  for (int I = 0; I < 10; ++I)
    X = X + strlen(S);
  return X;
}
//SAFE: Printing analysis 'Dependency Analysis (Metadata)' for function 'foo':
//SAFE:  loop at depth 1 stdlib_1.c:5:3
//SAFE:    induction:
//SAFE:     <I:5[5:3], 4>:[Int,0,10,1]
//SAFE:    reduction:
//SAFE:     <X:4, 4>:add
//SAFE:    read only:
//SAFE:     <S:3, 8>
//SAFE:    lock:
//SAFE:     <I:5[5:3], 4>
//SAFE:    header access:
//SAFE:     <I:5[5:3], 4>
//SAFE:    explicit access:
//SAFE:     <I:5[5:3], 4> | <S:3, 8> | <X:4, 4>
//SAFE:    address access:
//SAFE:     strlen():6:13
//SAFE:    explicit access (separate):
//SAFE:     <I:5[5:3], 4> <S:3, 8> <X:4, 4>
//SAFE:    lock (separate):
//SAFE:     <I:5[5:3], 4>
//SAFE:    address access (separate):
//SAFE:     strlen():6:13
//SAFE:    direct access (separate):
//SAFE:     <I:5[5:3], 4> <S:3, 8> <X:4, 4> strlen():6:13
