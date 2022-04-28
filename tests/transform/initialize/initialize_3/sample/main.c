int main() {
  int i;
  int arr1[50], arr2[50];

  for (i = 0; i < 1000; i++) {
    for (int i0 = 0; i0 < 50; i0++) {
      arr1[i0] = 1;
    }
    for (int i0 = 0; i0 < 20; i0++) {
      arr2[i0] = 2;
    }
  }
  return 0;
}