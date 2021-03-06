static int firstrow, lastrow;

void conj_grad(int * restrict colidx, int * restrict rowstr,
               double *restrict a, double *restrict p, double *restrict q) {
    int j, k;
    double sum;
    for (j = 0; j < lastrow - firstrow + 1; j++) {
      sum = 0.0;
      for (k = rowstr[j]; k < rowstr[j + 1]; k++) {
        sum = sum + a[k] * p[colidx[k]];
      }
      q[j] = sum;
    }
}
