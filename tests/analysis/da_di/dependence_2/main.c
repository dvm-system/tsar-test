double A[100];
int X;

void foo(int Flag) {
  for (int I = 0; I < 100; ++I) {
    // LLVM merge two if-stmt and implicitly transform it to
    // if (Flag) { ... } else { ... }
    // This allow us to perform analysis.
    if (Flag)
      X = A[I];
   A[I] = A[I] + 1;
   if (Flag)
     A[I+1] = X;
  }
}
