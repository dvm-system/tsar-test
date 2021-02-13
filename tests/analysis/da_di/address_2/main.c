int B[10];

void foo(int X, char Y) {
  double A[2];
  A[0] = X;
  A[1] = X;
  *((char *)A + 1) = Y;
  for (int I = 0; I < 10; ++I)
    B[I] = A[0] + A[1];  
}
