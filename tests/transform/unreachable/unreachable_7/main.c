int main() {
#pragma spf transform removeunreachable
{
  if (1 || 0)
    return 0;
  return 1;
}
}
