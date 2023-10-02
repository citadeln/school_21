#include "../s21_math.h"
// писос ну и душные лекции конечно по этим логарифмам и не понятные и
// бесячие...
//  lg - логарифм с основанием 10,
//  log логорифм с произвольным основанием,
//  ln - натуральный логарифм основание = e = 2.718281828...
//  нам нужен только натуральный логарифм #спасибо хоспаде йесусе

long double s21_log(double x) {
  long double result = 0.0;

  if (x == 0) {
    result = S21_INF_NEG;  // Возвращаем -бесконечность при x = 0
  } else if (x == S21_INF_POS) {
    result = x;
  } else if (x < 0) {
    result = S21_NAN_NEG;  // Возвращаем -NaN при x < 0
  } else if (x == 1.0) {
    result = 0.0;  // Логарифм от 1 равен 0
  } else {
    int e_repeat = 0;
    for (; x >= S21_E; e_repeat++)
      x /= S21_E;  // FMATH/Выполняем цикл пока х больше е и считаем сколько раз
                   // пришлось его поделить

    for (int i = 0; i < TOCHNOST; i++) {  // FMATH //от количества точности
                                          // зависит кто бы подумал - точность
      long double compare = result;
      result = compare +
               2 * (x - s21_exp(compare)) / (x + s21_exp(compare));  // FMATH
    }
    result += e_repeat;  // прибовляем количество репитов которое понадобилось
                         // чтобы уменьшить x до значений е зачем то..
  }
  return result;
}