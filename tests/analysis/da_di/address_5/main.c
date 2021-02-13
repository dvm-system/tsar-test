void init(int **P);
void exec(int *P);

void bar() {
  int *P;
  int S;
  for (int I = 0; I < 10; ++I) {    
    init(&P);
    exec(P);
  }
}
