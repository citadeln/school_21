#include "../s21_math.h"

int s21_abs(int x) {
  int result = 0;
  if (x == 0)
    result = 0;
  else
    result = x < 0 ? -x : x;

  return result;
}

/*
{
  long int result = 0;
  if (x == S21_INF_POS || x == S21_INF_NEG || x == S21_ZERO_POS ||
      x == S21_ZERO_NEG)
    result = x;
  else if (S21_ISNAN(x))
  {
    result = S21_NAN;
  }
  else
    result = x < 0 ? -x : x;

  return result;
}

*/