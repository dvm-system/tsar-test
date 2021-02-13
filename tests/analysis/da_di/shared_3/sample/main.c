int IStart, IEnd;

void foo(double *U) {
  for (int I = IStart; I < IEnd; I = I + 5)
    U[I] = U[I] + 1;
}
