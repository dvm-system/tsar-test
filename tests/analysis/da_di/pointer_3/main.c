void bar(int *);

int foo(int **V, int N) {
  int *Buffer = *V;
  for(int I = 0; I < N; I++ )
    bar(Buffer);	
  return 0;
}
