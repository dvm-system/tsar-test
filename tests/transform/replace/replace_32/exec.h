void init(STy *S) {
  S->A = S->B = 5;
}

int main() {
  STy S;
#pragma spf transform replace(S) nostrict
  init(&*&S);
  return S.A + S.B;
}
