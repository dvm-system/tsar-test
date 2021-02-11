void bar(int Y);

void foo(int X) {
  int Y;
#pragma spf metadata replace(bar(Y))
}

