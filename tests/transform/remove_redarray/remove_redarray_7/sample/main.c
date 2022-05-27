
int main() {
  int X[3];
  double Y[3];

  int X_subscr_0_0 = X[0], X_subscr_1_0 = X[1], X_subscr_2_0 = X[2];
  double Y_subscr_0_0 = Y[0], Y_subscr_1_0 = Y[1], Y_subscr_2_0 = Y[2];
  for (int i = 0; i < 10; i++) {
    switch (i) {
    case 0:
      X_subscr_0_0 = i + 1;
      break;
    case 1:
      X_subscr_1_0 = i + 1;
      break;
    case 2:
      X_subscr_2_0 = i + 1;
      break;
    };
    switch (i) {
    case 0:
      Y_subscr_0_0 = 2 * i;
      break;
    case 1:
      Y_subscr_1_0 = 2 * i;
      break;
    case 2:
      Y_subscr_2_0 = 2 * i;
      break;
    };
    switch (i) {
    case 0:
      X_subscr_0_0 = X_subscr_0_0 + 2;
      break;
    case 1:
      X_subscr_1_0 = X_subscr_1_0 + 2;
      break;
    case 2:
      X_subscr_2_0 = X_subscr_2_0 + 2;
      break;
    };
  }
  X[0] = X_subscr_0_0;
  X[1] = X_subscr_1_0;
  X[2] = X_subscr_2_0;
  Y[0] = Y_subscr_0_0;
  Y[1] = Y_subscr_1_0;
  Y[2] = Y_subscr_2_0;
}