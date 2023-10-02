#include "../s21_math.h"

long double s21_exp(double x) {
  long double res = 1.0;
  if (S21_ISNAN(x)) {  // c виду 0уета но  nan != nan
    res = x;  // exp возвращает тот нан который внего подали
  } else if (x == S21_INF_POS) {
    res = S21_INF_POS;
  } else if (x == S21_INF_NEG) {
    res = 0;
  } else if (x == S21_ZERO_NEG) {
    res = 1;
  } else {
    int n = 1;
    long double a = x;
    long double current_term = 1;
    if (x < 0.) a = -x;

    for (int i = 0; i < TOCHNOST; i++) {
      current_term *= a / n++;
      res += current_term;
    }
    if (x < 0.) res = 1 / res;
  }
  return res;
}