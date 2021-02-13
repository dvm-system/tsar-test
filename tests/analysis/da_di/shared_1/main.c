double U[100][100];

void foo(int I) {
  for (int J = 0; J < 100; ++J)
    U[I][J] = U[I][J] + 1;  
}
