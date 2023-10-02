#include "../s21_math.h"

long double s21_asin(double x) {
  long double res = 0;
  if (x < -1.0 || x > 1.0) {
    res = S21_NAN;
  } else if (S21_ISNAN(x)) {
    res = S21_NAN;
  } else if (x == 1) {
    res = S21_PI_2;
  } else if (x == -1) {
    res = -S21_PI_2;
  } else {
    long double term = x;
    while (s21_fabs(s21_sin(term) - x) > 1e-10) {
      term = term - (s21_sin(term) - x) / s21_cos(term);
    }
    res = term;
  }
  return res;
}
