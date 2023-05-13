int A[100];

int f(int N) {
	int S = 0;
	__builtin_assume(N > 4);
	for (int K = 0; K < 10; K++) {
	    for (int I = 0; I < N; I++)
		    A[I] = I + I;
		for (int I = 2; I < N-2; I++)
		    S += A[I];
	}
	return S;
}
