#include "../s21_math.h"

long double s21_acos(double x) {
  long double res = 0;
  if (x < -1.0 || x > 1.0) {
    res = S21_NAN;
  } else if (x == S21_INF_POS) {
    res = S21_INF_POS;
  } else if (x == S21_INF_NEG) {
    res = 0;
  } else if (S21_ISNAN(x)) {
    res = S21_NAN;
  } else if (x == 1) {
    res = 0;
  } else if (x == -1) {
    res = S21_PI;
  } else if (x == 0) {
    res = S21_PI_2;
  } else if ((1 - s21_fabs(x)) < 0.0000000001) {
    res = 3.14159253253218739843077;
  } else {
    res = S21_PI_2 - s21_asin(x);
  }
  return res;
}
