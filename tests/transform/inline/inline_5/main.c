int f() { return 0; }

void f1() {
  for (int I = 0; I < 10; ++I) {
    #pragma spf transform inline
    f();
 }
}

void f2() {
  #pragma spf transform inline
  for (int I = 0; I < 10; I = I + f());
}

void f3() {
  #pragma spf transform inline
  for (int I = 0; I < f(); ++I);
}

void f4() {
  #pragma spf transform inline
  for (int I = f(); I < 10; ++I);
}
