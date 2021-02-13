int X;
int * foo() { return &X; }

int main() {
  int *P;
  int S = 0;
  // Note, that 'instcombine' after loop rotate moves call of foo() outside
  // the loop. Hence, usage of address of X inside foo() becomes redundant.
  // This allow to determine that X can be privitized in case of
  // corresponding transformation of a source code.
  for (int I = 0; I < 10; ++I) {    
    X = I;
    S += X;
    P = foo();
  }
  // P implicitly refencese X (via foo()) and X has been updated in a loop.
  return S + *P;
}
