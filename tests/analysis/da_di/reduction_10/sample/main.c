void bar(int *S);

int foo() {
  int S;
  bar(&S);
  for (int I = 0; I < 10; ++I)
    S = S * I;
  return S;
}