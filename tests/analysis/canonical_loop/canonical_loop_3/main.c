void foo() {
  int I;
  for (I = 0; I < 10; --I);
}
//CHECK: Printing analysis 'Canonical Form Loop Analysis' for function 'foo':
