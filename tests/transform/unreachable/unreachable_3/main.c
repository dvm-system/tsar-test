int main(int Argc, char **Argv) {
#pragma spf transform removeunreachable
{
  while(0) {}
  for(; 0;) {}
  for(int I; 0; ++I) {}
  return 0;
}
}
