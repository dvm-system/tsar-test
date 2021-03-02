#define RESULT(S) double S = 0;

double bar() {
  RESULT(X)
  return X;
}