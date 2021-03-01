int * foo(int *X) {
  ++*X;
  return X;
}

void bar(void *X) {
  ++(*(foo(X)));
}