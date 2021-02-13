double A[10][10];

void bar(double (*A)[10]);

void foo() {
  bar(A);
  for (int I = 0; I < 10; ++I)
    for (int J = 0; J < 10; ++J)
      A[I][J] = A[I-1][J] * 2;
}
