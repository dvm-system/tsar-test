void foo(int **X) {
  *(*(X + 1) + 1) = 10;
}

