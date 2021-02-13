double A[100];

void foo() {
  for (int I = 98; I >= 0; --I)
    A[I] = A[I + 1];
}
