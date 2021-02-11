int bar();

int foo() {
#pragma spf transform replace with(foo)
  return bar();
}

