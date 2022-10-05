
int main(int Argc, char **Argv) {
#pragma spf transform removeunreachable
{
  int X;
  if ((X = Argc) > 1)
    return X;
  else
    int Argc = X;
  return X - 1;
}
}
