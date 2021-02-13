int JStart;

double foo() {
  double U[100];
  int I, J;
  JStart = 0;
  for (int I = 0; I < 100; I = I + 10) {
    // JStart is global, so SCEV could not be built accurately
    // and analysis will fail for outer loop.
    for (J = JStart; J < 10; ++J)
      U[I + J] = U[I + J] + 1;
  }
  return U[50];
}
//SAFE: Printing analysis 'Dependency Analysis (Metadata)' for function 'foo':
//SAFE:  loop at depth 1 shared_20.c:7:3
//SAFE:    private:
//SAFE:     <J:5, 4>
//SAFE:    output:
//SAFE:     <U:4:10, 800>
//SAFE:    anti:
//SAFE:     <U:4:10, 800>
//SAFE:    flow:
//SAFE:     <U:4:10, 800>
//SAFE:    induction:
//SAFE:     <I:7[7:3], 4>:[Int,0,100,10]
//SAFE:    read only:
//SAFE:     <JStart, 4>
//SAFE:    lock:
//SAFE:     <I:7[7:3], 4>
//SAFE:    header access:
//SAFE:     <I:7[7:3], 4>
//SAFE:    explicit access:
//SAFE:     <I:7[7:3], 4> | <J:5, 4> | <JStart, 4>
//SAFE:    explicit access (separate):
//SAFE:     <I:7[7:3], 4> <J:5, 4> <JStart, 4>
//SAFE:    lock (separate):
//SAFE:     <I:7[7:3], 4>
//SAFE:    direct access (separate):
//SAFE:     <I:7[7:3], 4> <J:5, 4> <JStart, 4> <U:4:10, 800>
//SAFE:   loop at depth 2 shared_20.c:10:5
//SAFE:     shared:
//SAFE:      <U:4:10, 800>
//SAFE:     induction:
//SAFE:      <J:5, 4>:[Int,,,1]
//SAFE:     read only:
//SAFE:      <I:7[7:3], 4>
//SAFE:     lock:
//SAFE:      <J:5, 4>
//SAFE:     header access:
//SAFE:      <J:5, 4>
//SAFE:     explicit access:
//SAFE:      <I:7[7:3], 4> | <J:5, 4>
//SAFE:     explicit access (separate):
//SAFE:      <I:7[7:3], 4> <J:5, 4>
//SAFE:     lock (separate):
//SAFE:      <J:5, 4>
//SAFE:     direct access (separate):
//SAFE:      <I:7[7:3], 4> <J:5, 4> <U:4:10, 800>
