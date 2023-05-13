int A[10][2];

int f(int N) {
    int S = 0;
    __builtin_assume(N > 0);
    for (int K = 0; K < 10; K++) {
        for (int I = 0; I < N; I++) {
            A[I][0] = I;
            A[I][1] = I + 2;
        }
        for (int J = 0; J < N; ++J)
            S += A[J][0] * A[J][1];
    }
    return S;
}
