int bar();
int baz();

int foo() {
#pragma spf transform replace with(baz) with(foo)
  return bar();
}

