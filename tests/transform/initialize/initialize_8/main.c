int main() {
  int i;
  int arr1[10], arr2[10][20];

  for (i = 0; i < 1000; i++) {
    #pragma spf transform initialize(arr1 = arr2)
  }
  return 0;
}