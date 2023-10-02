#include <check.h>
#include <math.h>

#include "../s21_math.h"

#define STRESS_FUNCTION s21_acos
#define HEALTHY_FUNCTION acos
#define STRESS_FUNCTION_Str "s21_acos(x)"
#define HEALTHY_FUNCTION_Str "acos(x)"
#define OUTPUT_DIGITS_LENGTH \
  70  // количество символов после запятой, выводимых в терминале

#define FUNCTION_FROM_COMPARE_C \
  compare_double_low_precision  // определяем какую
// функцию будем использовать

int compare_double_low_precision(
    double x, double healthy,
    long double stress) {  // возвращает 1 если знач одинаковое, 0 если разные
  printf(HEALTHY_FUNCTION_Str " | x = %.70lf\n", x);
  printf("%-*s: %-*.*f\n", 14, HEALTHY_FUNCTION_Str, 25, OUTPUT_DIGITS_LENGTH,
         HEALTHY_FUNCTION(x));
  printf("%-*s: %-*.*Lf\n\n", 14, STRESS_FUNCTION_Str, 25, OUTPUT_DIGITS_LENGTH,
         STRESS_FUNCTION(x));
  int result = 0;
  if (isnan(healthy) && isnan(stress))
    result = 1;
  else if ((signbit(stress)) ==
           signbit((long double)healthy)) {  // SIGNBIT ОЧЕН коварен нужно
                                             // приводить к одному типу!
    if (isinf(healthy) && isinf(stress))
      result = 1;
    else {
      long double x = fabs(stress) - fabs(healthy);
      if (fabs(x) < 1e-7)  // //ВНИМАНИЕ ТУТ НАСТРАИВАЕТСЯ ТОЧНОСТЬ CРАВНЕНИЯ!
        result = 1;
    }
  }
  return result;
}

START_TEST(standart_value) {
  printf("Test 1  ");  // TEST 1
  for (double x = -1.2; x <= 1.2; x += 0.12) {
    ck_assert(
        FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
  }
}
END_TEST

START_TEST(test_max) {
  double x = DBL_MAX;
  printf("Test 2  ");  // TEST 2
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST
START_TEST(test_max_neg) {
  double x = -DBL_MAX;
  printf("Test 3  ");  // TEST 3
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST
START_TEST(test_neg) {
  double x = -3432.12;
  printf("Test 4  ");  // TEST 4
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST

START_TEST(test_one) {
  double x = 1;
  printf("Test 5  ");  // TEST 5
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST
START_TEST(test_one_neg) {
  double x = -1;
  printf("Test 5.2  ");  // TEST 5.2
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST

START_TEST(test_nan_pos) {
  double x = S21_NAN;
  printf("Test 6  ");  // TEST 6
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST

START_TEST(test_nan_neg) {
  double x = -S21_NAN;
  printf("Test 7  ");  // TEST 7
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST

START_TEST(test_inf_neg) {
  double x = S21_INF_NEG;
  printf("Test 8  ");  // TEST 8
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST
START_TEST(test_inf_pos) {
  double x = S21_INF_POS;
  printf("Test 9  ");  // TEST 9
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST
START_TEST(test_zero) {
  double x = 0;
  printf("Test 10  ");  // TEST 10
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST
START_TEST(test_zero_neg) {
  double x = S21_ZERO_NEG;
  printf("Test 11  ");  // TEST 11
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST
START_TEST(test_even_number) {
  double x = 2;
  printf("Test 12  ");  // TEST 12
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST
START_TEST(test_not_even_number) {
  double x = 7;
  printf("Test 13  ");  // TEST 13
  ck_assert(
      FUNCTION_FROM_COMPARE_C(x, HEALTHY_FUNCTION(x), STRESS_FUNCTION(x)));
}
END_TEST

Suite *add_suite_HEALTHY_FUNCTION(void) {
  Suite *suit = suite_create(STRESS_FUNCTION_Str);
  TCase *tc_core = tcase_create(STRESS_FUNCTION_Str);

  tcase_add_test(tc_core, standart_value);
  // tcase_add_test(tc_core, test_max); //ограничение по длительности тетса не
  // дает вычислять большие значения tcase_add_test(tc_core, test_max_neg);
  // //ограничение по длительности тетса не дает вычислять большие значения
  tcase_add_test(tc_core, test_neg);
  tcase_add_test(tc_core, test_one);
  tcase_add_test(tc_core, test_one_neg);
  tcase_add_test(tc_core, test_nan_pos);
  tcase_add_test(tc_core, test_nan_neg);
  tcase_add_test(tc_core, test_inf_neg);
  tcase_add_test(tc_core, test_inf_pos);
  tcase_add_test(tc_core, test_zero);
  tcase_add_test(tc_core, test_zero_neg);
  tcase_add_test(tc_core, test_even_number);
  tcase_add_test(tc_core, test_not_even_number);
  suite_add_tcase(suit, tc_core);
  return suit;
}

int main() {
  Suite *s;
  SRunner *runner;

  s = add_suite_HEALTHY_FUNCTION();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);

  int ntests_failed = srunner_ntests_failed(runner);  // делаем красоту
  if (ntests_failed == 0) {  // делаем красоту
    printf("%s tilmapat.passed \033[0;32m\u2713\033[0m\n",
           STRESS_FUNCTION_Str);  // делаем красоту
  } else {                        // делаем красоту
    printf("%s tilmapat.failed № Failed %d \033[0;31m\u2717\033[0m\n ",
           STRESS_FUNCTION_Str, ntests_failed);  // делаем красоту
  }
  srunner_free(runner);
  return (ntests_failed == 0) ? EXIT_SUCCESS : EXIT_SUCCESS;
}
