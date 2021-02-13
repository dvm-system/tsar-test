int IStart, IEnd, IStep;

void foo(double * restrict U) {
  // Step of induction is a gloabal variable which can not be promoted.
  // Hence, it is not possible to build AddRec SCEV for induction and
  // data dependence analysis will fail and it assumes dependence.
  for (int I = IStart; I < IEnd; I = I + IStep)
    U[I] = U[I] + 1;
}
//SAFE: Printing analysis 'Dependency Analysis (Metadata)' for function 'foo':
//SAFE:  loop at depth 1 shared_6.c:7:3
//SAFE:    output:
//SAFE:     <*U:3, ?> | <I:7[7:3], 4>
//SAFE:    anti:
//SAFE:     <*U:3, ?> | <I:7[7:3], 4>
//SAFE:    flow:
//SAFE:     <*U:3, ?> | <I:7[7:3], 4>
//SAFE:    read only:
//SAFE:     <IEnd, 4> | <IStep, 4> | <U:3, 8>
//SAFE:    lock:
//SAFE:     <I:7[7:3], 4> | <IEnd, 4>
//SAFE:    header access:
//SAFE:     <I:7[7:3], 4> | <IEnd, 4>
//SAFE:    explicit access:
//SAFE:     <I:7[7:3], 4> | <IEnd, 4> | <IStep, 4> | <U:3, 8>
//SAFE:    explicit access (separate):
//SAFE:     <I:7[7:3], 4> <IEnd, 4> <IStep, 4> <U:3, 8>
//SAFE:    lock (separate):
//SAFE:     <I:7[7:3], 4> <IEnd, 4>
//SAFE:    direct access (separate):
//SAFE:     <*U:3, ?> <I:7[7:3], 4> <IEnd, 4> <IStep, 4> <U:3, 8>
