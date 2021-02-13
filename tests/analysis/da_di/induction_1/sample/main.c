int Start, End;

void foo(int * restrict A) {
  for (int I = End - 1; I >= Start; --I)
    A[I] = I;
}
