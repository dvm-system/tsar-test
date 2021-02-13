static int FirstCol, LastCol;
static int Data[100];

int foo(int S) {
  int I;
  for (I = 0; I < LastCol - FirstCol + 1; ++I) {
    S = S * Data[I];
  }
  return S;
}
