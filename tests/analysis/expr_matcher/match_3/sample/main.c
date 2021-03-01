int bar(int I, int J);
int foo() {
  int (*f)() = bar;
  return f(f(5, 6), f(2, 3));
}

