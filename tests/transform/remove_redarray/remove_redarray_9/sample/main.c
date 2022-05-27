
int main() {
  int X[10];
  double Y[15];

  int X_subscr_0_0 = X[0], X_subscr_1_0 = X[1], X_subscr_2_0 = X[2],
      X_subscr_3_0 = X[3], X_subscr_4_0 = X[4], X_subscr_5_0 = X[5],
      X_subscr_6_0 = X[6], X_subscr_7_0 = X[7], X_subscr_8_0 = X[8],
      X_subscr_9_0 = X[9];
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
    case 3:
      X_subscr_3_0 = i + 1;
      break;
    case 4:
      X_subscr_4_0 = i + 1;
      break;
    case 5:
      X_subscr_5_0 = i + 1;
      break;
    case 6:
      X_subscr_6_0 = i + 1;
      break;
    case 7:
      X_subscr_7_0 = i + 1;
      break;
    case 8:
      X_subscr_8_0 = i + 1;
      break;
    case 9:
      X_subscr_9_0 = i + 1;
      break;
    };
    Y[i] = 2 * i;
    switch (i) {
    case 0:
      X_subscr_0_0 = Y[i];
      break;
    case 1:
      X_subscr_1_0 = Y[i];
      break;
    case 2:
      X_subscr_2_0 = Y[i];
      break;
    case 3:
      X_subscr_3_0 = Y[i];
      break;
    case 4:
      X_subscr_4_0 = Y[i];
      break;
    case 5:
      X_subscr_5_0 = Y[i];
      break;
    case 6:
      X_subscr_6_0 = Y[i];
      break;
    case 7:
      X_subscr_7_0 = Y[i];
      break;
    case 8:
      X_subscr_8_0 = Y[i];
      break;
    case 9:
      X_subscr_9_0 = Y[i];
      break;
    };
  }
  X[0] = X_subscr_0_0;
  X[1] = X_subscr_1_0;
  X[2] = X_subscr_2_0;
  X[3] = X_subscr_3_0;
  X[4] = X_subscr_4_0;
  X[5] = X_subscr_5_0;
  X[6] = X_subscr_6_0;
  X[7] = X_subscr_7_0;
  X[8] = X_subscr_8_0;
  X[9] = X_subscr_9_0;
}