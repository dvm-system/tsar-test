int bar();

int foo() {
  int (*baz)() = bar;
#pragma spf transform replace with(foo)
  return baz();
}

