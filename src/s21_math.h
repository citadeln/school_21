#ifndef s21_math
#define s21_math

#include <limits.h>  //для инт макс
// #include <math.h>  // !!!!!!!!УДАЛИТЬ!!!!!!
#include <stdio.h>
#include <stdlib.h>

// #define _POSIX_C_SOURCE 200809L

#define S21_NAN (0.0f / 0.0f)
#define S21_NAN_NEG (-0.0f / 0.0f)
#define S21_ZERO_NEG -(0.0)
#define S21_ZERO_POS (0.0)
#define S21_INF_NEG (-1.0 / 0.0)
#define S21_INF_POS (1.0 / 0.0)
#define S21_ISNAN(x) ((x) != (x))
#define S21_PI 3.14159265358979323846L
#define S21_PI_2 1.57079632679489661923L
#define S21_E 2.71828182845904523536L  // всеже с большой буквы давайте
#define S21_IS_INF(x) ((x) == S21_INF_POS || (x) == S21_INF_NEG)
// #define S21_ISINF __builtin_isinf
#define S21_PI_12 (S21_PI / 12.F)     // atan
#define S21_PI_6 (S21_PI / 6.F)       // atan
#define S21_SQRT_3 (1.732050807569F)  // atan
#define S21_IS_NEG_ZERO(x) ((x) == 0.0 && (1.0 / (x)) < 0)
#define TOCHNOST 500

int s21_abs(int x);  // вычисляет абсолютное значение целого числа
long double s21_acos(double x);  // вычисляет арккосинус
long double s21_asin(double x);  // вычисляет арксинус
long double s21_atan(double x);  // вычисляет арктангенс
long double s21_ceil(double x);  // возвращает ближайшее целое число, не меньшее
                                 // заданного значения
long double s21_cos(double x);   // вычисляет косинус
long double s21_exp(
    double x);  // возвращает значение e, возведенное в заданную степень
long double s21_fabs(
    double x);  // вычисляет абсолютное значение числа с плавающей точкой
long double s21_floor(double x);  // возвращает ближайшее целое число, не
                                  // превышающее заданное значение
long double s21_fmod(double x,
                     double y);  // остаток операции деления с плавающей точкой
long double s21_log(double x);  // вычисляет натуральный логарифм
long double s21_pow(double base,
                    double exp);  // возводит число в заданную степень
long double s21_sin(double x);  // вычисляет синус
long double s21_sqrt(double x);  // вычисляет квадратный корень
long double s21_tan(double x);  // вычисляет тангенс
#endif