int X;

void foo(long long * restrict A) {
 for (int I = 0; I < 10; ++I)
    A[I] = ((long long) &X) + 1;
}
