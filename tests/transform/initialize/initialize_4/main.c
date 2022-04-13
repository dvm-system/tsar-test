int main() {
  int i, N = 70;
  int arr1[50], arr2[50];
  int brr1[60], brr2[60];
  int *crr1, *crr2;

  /*crr1 = (int*)malloc(N * sizeof(int));
  crr2 = (int*)malloc(N * sizeof(int));*/

  for (i = 0; i < 1000; i++) {
    #pragma spf transform initialize(arr1 = arr2, brr1 = brr2 [20], crr1 = crr2 [30])
  }
  return 0;
}