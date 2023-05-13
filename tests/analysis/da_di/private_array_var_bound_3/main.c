void f(int * restrict A, int * restrict B, int N) {
    __builtin_assume(N > 1);
    for (int K = 0; K < 10; K++) {
        for (int I = 0; I < N; I++)
            A[I] = I * I;
        B[0] = 0;
        for (int I = 1; I < N; ++I)
            B[I] = A[I] + A[I-1];
    }
}
