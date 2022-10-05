int X;

int main() {
#pragma spf transform removeunreachable
{
  return (X = 1, X) ? X - 1 : 1;
}
}
