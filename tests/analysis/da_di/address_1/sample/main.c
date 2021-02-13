void bar(double *X, double Y);

void foo (int N) {
  double X;
  for (int I = 0; I < 10; ++I)
    bar(&X, X);
}
