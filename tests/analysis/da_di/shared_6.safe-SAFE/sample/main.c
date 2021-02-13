int IStart, IEnd, IStep;

void foo(double * restrict U) {
  // Step of induction is a gloabal variable which can not be promoted.
  // Hence, it is not possible to build AddRec SCEV for induction and
  // data dependence analysis will fail and it assumes dependence.
  for (int I = IStart; I < IEnd; I = I + IStep)
    U[I] = U[I] + 1;
}
