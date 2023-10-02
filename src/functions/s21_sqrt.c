#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double res = 0;
  if (S21_ISNAN(x)) {
    res = x;
  } else if (x == 0) {
    res = x;
  } else if (x == S21_INF_POS) {
    res = S21_INF_POS;
  } else if (x == S21_INF_NEG) {
    res = S21_NAN_NEG;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}