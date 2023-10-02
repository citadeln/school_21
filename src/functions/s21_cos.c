#include "../s21_math.h"

long double s21_cos(double x) {
  long double res = 1.0;
  long double xl = s21_fmod(x, 2.0 * S21_PI);

  if (S21_ISNAN(x) || s21_fabs(x) == S21_INF_POS) {
    res = S21_NAN;
  } else if (x == 0) {
    res = 1;
  } else {
    for (double pow = 0.0, num = 1.0; s21_fabs(num / res) > 1e-10; pow += 2.0) {
      num = (-num * xl * xl) / ((pow + 1.0) * (pow + 2.0));
      res += num;
    }
  }
  return res;
}
