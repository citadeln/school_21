#include "../s21_math.h"

// int is_even(double x){ //Число(степень) четная? 1 если да 0 если нет
//   if ((int)x % 2 == 0) return 1;
//   else return 0;
// }

int not_even(double x) {  // Число(степень) не четная? 1 если да 0 если нет
  if ((int)x % 2 != 0)
    return 1;
  else
    return 0;
}

long double s21_pow(double base, double power) {
  long double res = 0;
  int temp = 0;

  if (base < 0 && !S21_IS_INF(power) && s21_floor(power) != power) {
    return S21_NAN;
  }

  if (S21_ISNAN(base) || S21_ISNAN(power)) {
    res = S21_NAN;
  } else if ((base == 1 || S21_ISNAN(power)) ||
             (power == 0 || S21_ISNAN(base))) {
    res = 1.0;
  } else if (S21_IS_NEG_ZERO(base) && not_even(power)) {
    res = S21_ZERO_NEG;
  } else if ((base == S21_ZERO_POS && (power > 0 && not_even(power))) ||
             (base == 0 && (power > 0 && !(not_even(power)))) ||
             (s21_fabs(base) > 1 && power == S21_INF_NEG) ||
             (s21_fabs(base) < 1 && S21_IS_INF(power)) ||
             (base == S21_INF_NEG && (power < 0)) ||
             (base == S21_INF_POS && power < 0)) {
    res = S21_ZERO_POS;
  } else {
    if (base < 0) {
      if (not_even(power)) {
        temp = 1;
      }
      base = s21_fabs(base);
    }
    res = temp ? -(s21_exp(power * s21_log(base)))
               : s21_exp(power * s21_log(base));
  }
  return res;
}