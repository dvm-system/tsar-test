int * foo();
void bar(int *X);

int main() {
  int *X;
  X = foo();
  for (int I = 0; I < 100; ++I)
    bar(X);
  return 0;
}