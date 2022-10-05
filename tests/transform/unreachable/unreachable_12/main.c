int main(int Argc, char **Argv) {
#pragma spf transform removeunreachable
{
  for((void)Argc; 0;) {}
  for(int I; 0; ++I) {}
  for(; Argc = 0, 0;) {}
  for((void)Argc; Argc = 0, 0;) {}
  return 0;
}
}
