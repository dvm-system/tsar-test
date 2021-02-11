int bar();

int foo() {
  int (*baz)();
#pragma spf transform replace with(baz)
  return bar();
}

