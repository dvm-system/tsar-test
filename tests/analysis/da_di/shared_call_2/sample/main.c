int X;
long long bar() { return (long long)&X; }

long long foo() {
  long long S = 0;
  for (int I = 0; I < 10; ++I)
    S += bar();
  return S;
}
