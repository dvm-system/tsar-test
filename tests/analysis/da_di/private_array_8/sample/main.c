void test(int *a) {
    for (int j = 0; j < 10; ++j) {
        int b[2];
        for (int i = 0; i < 2; ++i) {
            b[i] = i;
        }
        a[0] = b[0];
    }
}

