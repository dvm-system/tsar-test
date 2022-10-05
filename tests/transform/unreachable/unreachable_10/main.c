
int main(int Argc, char **Argv) {
#pragma spf transform remove unreachable
{
  int X;
  if ((X = Argc) > 1)
    return 1;
  return X - 1;
}
}
