int main() {
  int i, N = 70;
  int arr1[50], arr2[50];
  int brr1[60], brr2[60];
  int *crr1, *crr2;

  /*crr1 = (int*)malloc(N * sizeof(int));
  crr2 = (int*)malloc(N * sizeof(int));*/

  for (i = 0; i < 1000; i++) {
    for (int i0 = 0; i0 < 50; i0++) {
      arr1[i0] = arr2[i0];
    }
    for (int i0 = 0; i0 < 20; i0++) {
      brr1[i0] = brr2[i0];
    }
    for (int i0 = 0; i0 < 30; i0++) {
      crr1[i0] = crr2[i0];
    }
  }
  return 0;
}