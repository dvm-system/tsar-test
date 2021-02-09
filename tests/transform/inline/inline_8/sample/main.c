int f2() { return 2; }
int f1() { 
#pragma spf transform inline
  return 1 + (0 || f2());
}
