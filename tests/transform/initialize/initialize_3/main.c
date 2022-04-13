int main() {
  int i;
  int arr1[50], arr2[50];

  for (i = 0; i < 1000; i++) {
    #pragma spf transform initialize(arr1 = 1, arr2 = 2 [20])
  }
  return 0;
}