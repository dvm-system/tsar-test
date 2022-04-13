int main() {
  int i;
  int arr1[5][10], arr2[5][10];

  for (i = 0; i < 1000; i++) {
    #pragma spf transform initialize(arr1 = arr2 [5][10][20])
  }
  return 0;
}