void init(STy *S) { S->A = S->B = 5; }

/* Replacement for void init(STy *S) */
void init_spf0(data_t *S_A0, data_t *S_B0) {
#pragma spf metadata replace(init({.A = S_A0, .B = S_B0}))
  (*S_A0) = (*S_B0) = 5;
}

int main() {
  STy S;

  init(&*&S);
  return S.A + S.B;
}

/* Replacement for int main() */
int main_spf0() {
#pragma spf metadata replace(main())
  data_t S_A1;
  data_t S_B1;
  init_spf0(&S_A1, &S_B1);
  return S_A1 + S_B1;
}
