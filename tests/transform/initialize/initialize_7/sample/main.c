int main() {
  int i;
  int **arr;

  /*arr = (int**)malloc(128 * sizeof(int*));
    for (i = 0; i < 128; i++) {
      arr[i] = (int*)malloc(256 * sizeof(int));
    }*/

  for (i = 0; i < 1000; i++) {
    for (int i0 = 0; i0 < 128; i0++) {
      for (int i1 = 0; i1 < 256; i1++) {
        arr[i0][i1] = 5;
      }
    }
  }
  return 0;
}