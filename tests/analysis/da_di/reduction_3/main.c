double foo(double S) {
  for (int J = 0; J < 10; ++J) {
    for (int I = 0; I < 10; ++I)
      S *= I * J;
    for (int I = 0; I < 10; ++I)
      S *= I;
  }
  return S;
}
