int X;

int main() {
#pragma spf transform removeunreachable
{
  return (X = 0, X) ? 1 : X;
}
}
