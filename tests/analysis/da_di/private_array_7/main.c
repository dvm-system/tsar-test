void foo(int *A) {
  double T[2][2];
  for (int I = 0; I < 100; ++I) { 
    T[0][0] = I;
    T[0][1] = I + 1;
    T[1][0] = I;
    T[1][1] = I - 1;
    for (int J = 0; J < 2; ++J)
      A[I] = T[0][J] * T[1][J];
    A[I] = A[I] + A[I+1];
  }
}

