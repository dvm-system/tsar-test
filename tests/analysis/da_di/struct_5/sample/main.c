struct STy { int X; double Y; };

double foo(struct STy S) {
  double Res = 0;
  for (int I = 0; I < S.X; ++I)
    Res += S.Y;
  return Res;
}
