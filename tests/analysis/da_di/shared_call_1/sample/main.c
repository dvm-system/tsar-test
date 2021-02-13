int bar(int I) { return I + 1; }

int foo() {
  int S = 0;
  for (int I = 0; I < 10; ++I)
    S += bar(I);
  return S;
}
