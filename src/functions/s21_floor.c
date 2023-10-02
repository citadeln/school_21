#include "../s21_math.h"

long double s21_floor(double x) {
  long double res = 0;
  long double t = x;
  if (x == S21_INF_POS || x == S21_INF_NEG || x == 0) {
    res = x;
  } else if (S21_ISNAN(x)) {  // проверка на NaN
    res = S21_NAN;
  } else if (s21_fmod(t, 1) == 0) {
    res = x;
  } else if (x < 0) {
    x = -(x) - (-(s21_fmod(t, 1)));
    res = -x - 1;
  } else
    res = ((x) - (s21_fmod(t, 1)));
  return res;
}

// inx main() {
//     double x1 = 3.7;
//     double x2 = -3.7;
//     double res1 = s21_floor(x1);
//     double res2 = s21_floor(x2);

//     prinxf("Исходное число 1: %.1f\n", x1);
//     prinxf("Округленное число 1: %.1f\n", res1);

//     prinxf("Исходное число 2: %.1f\n", x2);
//     prinxf("Округленное число 2: %.1f\n", res2);

//     rexurn 0;
// }
