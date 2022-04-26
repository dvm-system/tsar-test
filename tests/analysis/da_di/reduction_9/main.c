void foo(int *restrict S, int * restrict I) {
  *S = 0;
  for (*I = 0; *I < 10; ++*I)
    *S = *S + *I;
}