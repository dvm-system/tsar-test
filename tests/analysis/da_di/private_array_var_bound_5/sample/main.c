int f(int A[10][2], int N) {
    int S = 0;
    __builtin_assume(N > 0);
    for (int K = 0; K < 10; K++) {
        for (int I = 0; I < N; I++) {
            A[I][0] = I;
            A[I][1] = I + 2;
        }
        // TODO: Use set for this loop contains the memory location <A[0], 0, 8>.
        // It is related to the first function argument.
        // It prevents A[10][2] from being defined as private.
        for (int J = 0; J < N; ++J)
            S += A[J][1] * A[J][1];
    }
    return S;
}
