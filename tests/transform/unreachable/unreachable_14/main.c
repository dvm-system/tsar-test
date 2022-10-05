#define STMT X = 5

int main(int Argc, char **Argv) {
#pragma spf transform removeunreachable
{
  int X;
  goto L;
  STMT;
  L:  return 0;
}
}
