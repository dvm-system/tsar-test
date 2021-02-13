int foo(int Y) {
  int I, X;
  for (I = 0; I < 10; ++I) {
    if (Y > 0)
      X = I;
    if (Y > 0)
      X = X + 1;
  }
  return X;
}
//SAFE: Printing analysis 'Dependency Analysis (Metadata)' for function 'foo':
//SAFE:  loop at depth 1 private_6.c:3:3
//SAFE:    output:
//SAFE:     <X:2, 4>
//SAFE:    anti:
//SAFE:     <X:2, 4>
//SAFE:    flow:
//SAFE:     <X:2, 4>
//SAFE:    induction:
//SAFE:     <I:2, 4>:[Int,0,10,1]
//SAFE:    read only:
//SAFE:     <Y:1, 4>
//SAFE:    lock:
//SAFE:     <I:2, 4>
//SAFE:    header access:
//SAFE:     <I:2, 4>
//SAFE:    explicit access:
//SAFE:     <I:2, 4> | <X:2, 4> | <Y:1, 4>
//SAFE:    explicit access (separate):
//SAFE:     <I:2, 4> <X:2, 4> <Y:1, 4>
//SAFE:    lock (separate):
//SAFE:     <I:2, 4>
//SAFE:    direct access (separate):
//SAFE:     <I:2, 4> <X:2, 4> <Y:1, 4>
