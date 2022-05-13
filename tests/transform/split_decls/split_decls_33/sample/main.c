int main() {
  const volatile int a;
  const volatile int b;
  const volatile int c;

  volatile int const *x, y, z;
  int *ptr1;
  int *ptr2;

  int const *ptrToConst1, *ptrToConst2;
  int *const constPtr1, *const constPtr2;
  int const *const constPtrToConst1, constPtrToConst2;
  return 0;
}