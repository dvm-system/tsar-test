int IStart, IEnd;

void foo(double * restrict U, int IStep) {
  for (int I = IStart; I < IEnd; I = I + IStep)
    U[I] = U[I] + 1;
}
