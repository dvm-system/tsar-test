double A[100];

void foo() {
  int X = -1;
  for (int I = 98; I >= 0; I = I + X)
    A[I] = A[I + 1];
}
