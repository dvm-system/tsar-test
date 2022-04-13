int main() {
  int i;
  int arr1[5][6][7], arr2[5][6][7];
  for (i = 0; i < 1000; i++) {
    for (int i0 = 0; i0 < 2; i0++) {
      for (int i1 = 0; i1 < 3; i1++) {
        for (int i2 = 0; i2 < 4; i2++) {
          arr1[i0][i1][i2] = arr2[i0][i1][i2];
        }
      }
    }
  }
  return 0;
}