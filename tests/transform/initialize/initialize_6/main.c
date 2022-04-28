int main() {
  int i;
  int arr1[5][6][7], arr2[5][6][7];
  for (i = 0; i < 1000; i++) {
    #pragma spf transform initialize(arr1 = arr2 [2] [3] [4])
  }
  return 0;
}