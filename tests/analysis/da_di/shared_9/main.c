int IStart, IEnd, JEnd;

void foo(int N, int JStart, double * restrict * restrict U) {
  for (int I = IStart; I < IEnd; ++I)
    for (int J = JStart; J <  JEnd; ++J)
      U[I][J] = U[I][J] + 1;
}
//SAFE: Printing analysis 'Dependency Analysis (Metadata)' for function 'foo':
//SAFE:  loop at depth 1 shared_9.c:4:3
//SAFE:    private:
//SAFE:     <J:5[5:5], 4>
//SAFE:    output:
//SAFE:     <*U[?]:{6:17|3}, ?> <IEnd, 4> <JEnd, 4>
//SAFE:    anti:
//SAFE:     <*U[?]:{6:17|3}, ?> <IEnd, 4> <JEnd, 4>
//SAFE:    flow:
//SAFE:     <*U[?]:{6:17|3}, ?> <IEnd, 4> <JEnd, 4>
//SAFE:    induction:
//SAFE:     <I:4[4:3], 4>:[Int,,,1]
//SAFE:    read only:
//SAFE:     <*U:3, ?> | <JStart:3, 4> | <U:3, 8>
//SAFE:    lock:
//SAFE:     <*U[?]:{6:17|3}, ?> <IEnd, 4> <JEnd, 4> | <I:4[4:3], 4>
//SAFE:    header access:
//SAFE:     <*U[?]:{6:17|3}, ?> <IEnd, 4> <JEnd, 4> | <I:4[4:3], 4>
//SAFE:    explicit access:
//SAFE:     <*U[?]:{6:17|3}, ?> <IEnd, 4> <JEnd, 4> | <I:4[4:3], 4> | <J:5[5:5], 4> | <JStart:3, 4> | <U:3, 8>
//SAFE:    explicit access (separate):
//SAFE:     <I:4[4:3], 4> <IEnd, 4> <J:5[5:5], 4> <JEnd, 4> <JStart:3, 4> <U:3, 8>
//SAFE:    lock (separate):
//SAFE:     <I:4[4:3], 4> <IEnd, 4>
//SAFE:    direct access (separate):
//SAFE:     <*U:3, ?> <*U[?]:{6:17|3}, ?> <I:4[4:3], 4> <IEnd, 4> <J:5[5:5], 4> <JEnd, 4> <JStart:3, 4> <U:3, 8>
//SAFE:   loop at depth 2 shared_9.c:5:5
//SAFE:     output:
//SAFE:      <*U[?]:{6:17|3}, ?> <JEnd, 4>
//SAFE:     anti:
//SAFE:      <*U[?]:{6:17|3}, ?> <JEnd, 4>
//SAFE:     flow:
//SAFE:      <*U[?]:{6:17|3}, ?> <JEnd, 4>
//SAFE:     induction:
//SAFE:      <J:5[5:5], 4>:[Int,,,1]
//SAFE:     read only:
//SAFE:      <*U:3, ?> | <I:4[4:3], 4> | <U:3, 8>
//SAFE:     lock:
//SAFE:      <*U[?]:{6:17|3}, ?> <JEnd, 4> | <J:5[5:5], 4>
//SAFE:     header access:
//SAFE:      <*U[?]:{6:17|3}, ?> <JEnd, 4> | <J:5[5:5], 4>
//SAFE:     explicit access:
//SAFE:      <*U[?]:{6:17|3}, ?> <JEnd, 4> | <I:4[4:3], 4> | <J:5[5:5], 4> | <U:3, 8>
//SAFE:     explicit access (separate):
//SAFE:      <I:4[4:3], 4> <J:5[5:5], 4> <JEnd, 4> <U:3, 8>
//SAFE:     lock (separate):
//SAFE:      <J:5[5:5], 4> <JEnd, 4>
//SAFE:     direct access (separate):
//SAFE:      <*U:3, ?> <*U[?]:{6:17|3}, ?> <I:4[4:3], 4> <J:5[5:5], 4> <JEnd, 4> <U:3, 8>
