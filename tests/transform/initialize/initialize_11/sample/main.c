int main() {
  int i;
  int arr1[5][10], arr2[5][10];

  for (i = 0; i < 1000; i++) {
    for (int i0 = 0; i0 < 5; i0++) {
      for (int i1 = 0; i1 < 10; i1++) {
        arr1[i0][i1] = arr2[i0][i1];
      }
    }
  }
  return 0;
}