typedef double T;

struct Data {
  T Value;
};

struct STy {
  T (*F)(T);
  int NX;
  Data *D;
};

struct UnusedTy { };

void foo(STy *S, UnusedTy *U, double Val) {
  #pragma spf transform replace(S, U) nostrict
  for (int I = 0; I < S->NX; I += 2)
    S->D[I].Value = S->D[I + 1].Value = S->F(Val);
}
