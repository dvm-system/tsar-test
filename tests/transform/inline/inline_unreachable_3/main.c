int f() {return 3;}

void g() {
  #pragma spf transform inline
  0 ? f() : 4;
}

void h() {
  #pragma spf transform inline
  g();
}
