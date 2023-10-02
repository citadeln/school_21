#include "../s21_math.h"

// возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x) {
  long double res = 0;
  long double t = x;
  if (x == S21_INF_POS || x == S21_INF_NEG || x == S21_ZERO_NEG ||
      x == S21_ZERO_POS)
    res = x;
  else if (S21_ISNAN(x))  // проверка на NaN
    res = S21_NAN;
  else if (s21_fmod(x, 1) == 0)
    res = x;
  else if (x < 0) {
    x = -(x) - (-(s21_fmod(t, 1)));
    res = -x;
  } else if (s21_fabs(x) < 1)
    res = 1;
  else
    res = ((x) - (s21_fmod(t, 1)) + 1);
  return res;
}