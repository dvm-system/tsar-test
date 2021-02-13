struct STy { int X; double Y; };

double foo(int N) {
  struct STy S;
  double Res = 0;
  S.Y = S.X = N;
  for (int I = 0; I < S.X; ++I) {
    S.Y = I;
    Res += S.Y;
  }
  return Res;
}
