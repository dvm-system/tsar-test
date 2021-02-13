double U[100];
int IStart, IEnd;

void foo() {
  for (int I = IStart; I < IEnd; I = I + 5)
    U[I] = U[I] + 1;
}
