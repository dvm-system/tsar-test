int main() {
  int i;
  int **arr;

  /*arr = (int**)malloc(128 * sizeof(int*));
    for (i = 0; i < 128; i++) {
      arr[i] = (int*)malloc(256 * sizeof(int));
    }*/

  for (i = 0; i < 1000; i++) {
    #pragma spf transform initialize(arr = 5 [128] [256])
  }
  return 0;
}