int main() {
  int I, X;
  for (I = 0; I < 10; ++I)
    X = I;
  X = 2 * X;
  return X;
}
//SAFE: Printing analysis 'Dependency Analysis (Metadata)' for function 'main':
//SAFE:  loop at depth 1 private_2.c:3:3
//SAFE:    first private:
//SAFE:     <X:2, 4>
//SAFE:    second to last private:
//SAFE:     <X:2, 4>
//SAFE:    induction:
//SAFE:     <I:2, 4>:[Int,0,10,1]
//SAFE:    lock:
//SAFE:     <I:2, 4>
//SAFE:    header access:
//SAFE:     <I:2, 4>
//SAFE:    explicit access:
//SAFE:     <I:2, 4> | <X:2, 4>
//SAFE:    explicit access (separate):
//SAFE:     <I:2, 4> <X:2, 4>
//SAFE:    lock (separate):
//SAFE:     <I:2, 4>
//SAFE:    direct access (separate):
//SAFE:     <I:2, 4> <X:2, 4>
