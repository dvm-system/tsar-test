int A[100];

int f(int M, int N) {
	int S = 0;
	__builtin_assume(M > 0);
	__builtin_assume(M < N);
	for (int K = 0; K < 10; K++) {
	    for (int I = 0; I < M; I++)
		    A[I] = I + I;
	    for (int I = M; I < N; I++)
		    A[I] = 42 * I;
		for (int I = 0; I < N; I++)
		    S += A[I];
	}
	return S;
}
