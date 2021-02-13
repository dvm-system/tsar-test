void bar(double *A) { A[5] = 10; }

void foo(int N) {
  double A[N][10];
  // Dependence may exist because bar() could add offset to its parameter
  // and the same call may access different rows of A.
  // Option '-finbounds-subscripts' has no sense in this case.
  for (int I = 0; I < 10; ++I)
    bar(A[I]);
}
