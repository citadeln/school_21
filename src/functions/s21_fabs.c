#include "../s21_math.h"

long double s21_fabs(
    double x) {  // вычисляет абсолютное значение числа с плавающей точкой
  long double res = 0;
  if (x == S21_INF_NEG ||
      x == S21_INF_POS) {  // проверка на отрицательную бесконечность
    res = S21_INF_POS;
  } else if (x == 0) {  // проверка на -0
    res = 0;
  } else if (S21_ISNAN(x)) {  // проверка на NaN
    res = S21_NAN;
  } else {
    res = x < 0 ? -x : x;  // присваивание значения в зависимости от знака
  }

  return res;
}