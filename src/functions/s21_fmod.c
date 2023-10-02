#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  long long int mod;
  if (S21_ISNAN(x) || S21_ISNAN(y) || S21_IS_INF(x) || y == 0)
    res = S21_NAN;
  else if (S21_IS_INF(y) || x == S21_ZERO_POS || x == S21_ZERO_NEG)
    res = x;
  else {
    mod = x / y;
    res = x - mod * y;
  }
  return res;
}

/*
    if (x < 0 || y < 0)
      res = -abs((int)(x / y);
    else
      res = abs(x / y);

    res = x - res * y;
  }
  return res;
*/