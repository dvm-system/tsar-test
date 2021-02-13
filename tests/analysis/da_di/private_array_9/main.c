#include <inttypes.h>

void test(int *a) {
    for (int j = 0; j < 10; ++j) {
        uint8_t b[2][2][2];
        for (int i = 0; i < 2; ++i) {
            b[1][1][i] = i;
        }
        a[0] = b[0][0][j];
    }
}

