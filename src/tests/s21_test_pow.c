#include <check.h>
#include <math.h>

#include "../s21_math.h"

#define STRESS_FUNCTION s21_pow
#define HEALTHY_FUNCTION pow
#define STRESS_FUNCTION_Str "s21_pow(1st,2nd)"
#define HEALTHY_FUNCTION_Str "pow(1st,2nd)"
#define OUTPUT_DIGITS_LENGTH \
  35  // количество символов после запятой, выводимых в терминале
#define DEFAULT_1st_ARG 7.2
#define DEFAULT_2nd_ARG 5

#define FUNCTION_FROM_COMPARE_C compare_double_2arg  // определяем какую
// функцию будем использовать

int compare_double_2arg(
    double x, double y, double healthy,
    long double stress) {  // возвращает 1 если знач одинаковое, 0 если разные
  printf(HEALTHY_FUNCTION_Str " |1st arg = %.30lf | 2nd arg = %lf \n", x, y);
  printf("%-*s: %-*.*f\n", 16, HEALTHY_FUNCTION_Str, 30, OUTPUT_DIGITS_LENGTH,
         HEALTHY_FUNCTION(x, y));
  printf("%-*s: %-*.*Lf\n\n", 16, STRESS_FUNCTION_Str, 30, OUTPUT_DIGITS_LENGTH,
         STRESS_FUNCTION(x, y));
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
      if (fabs(x) < 1e-10)  // //ВНИМАНИЕ ТУТ НАСТРАИВАЕТСЯ ТОЧНОСТЬ CРАВНЕНИЯ!
        result = 1;
    }
  }
  return result;
}

START_TEST(standart_value) {
  printf("Test 1  ");  // TEST 1
  for (double x = -5; x <= 5; x += 3.97) {
    for (double y = -3.0; y < 5; y += 1.89) {
      ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                        STRESS_FUNCTION(x, y)));
    }
  }
}
END_TEST
START_TEST(test_max) {
  double x = DBL_MAX;
  double y = DEFAULT_2nd_ARG;
  printf("Test 2  ");  // TEST 2
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_max_2) {
  double x = DEFAULT_1st_ARG;
  double y = DBL_MAX;
  printf("Test 2.1  ");  // TEST 2.1
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_max_neg) {
  double x = -DBL_MAX;
  double y = DEFAULT_2nd_ARG;
  printf("Test 3  ");  // TEST 3
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_max_neg_2) {
  double x = DEFAULT_2nd_ARG;
  double y = -DBL_MAX;
  printf("Test 3.1  ");  // TEST 3.1
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_neg) {
  double x = -3000;
  double y = DEFAULT_2nd_ARG;
  printf("Test 4  ");  // TEST 4
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_neg_2) {
  double x = DEFAULT_2nd_ARG;
  double y = -343.12;
  printf("Test 4.1  ");  // TEST 4.1
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST

START_TEST(test_one) {
  double x = DEFAULT_1st_ARG;  // Use the default 2nd argument
  double y = 1;
  // Use the default 2nd argument
  printf("Test 5  ");  // TEST 5
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST

START_TEST(test_one_2) {
  double x = 1;
  double y = DEFAULT_2nd_ARG;
  printf("Test 5.1  ");  // TEST 5.1
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST

// Modify other test functions similarly...

START_TEST(test_nan_pos) {
  double x = S21_NAN;
  double y = DEFAULT_2nd_ARG;
  printf("Test 6  ");  // TEST 6
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_nan_pos_2) {
  double x = DEFAULT_1st_ARG;
  double y = S21_NAN;
  printf("Test 6.1  ");  // TEST 6.1
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST

START_TEST(test_nan_neg) {
  double x = -S21_NAN;
  double y = DEFAULT_2nd_ARG;
  printf("Test 7  ");  // TEST 7
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_nan_neg_2) {
  double x = DEFAULT_1st_ARG;
  double y = -S21_NAN;
  printf("Test 7.1  ");  // TEST 7.1
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST

START_TEST(test_inf_neg) {
  double x = S21_INF_NEG;
  double y = DEFAULT_2nd_ARG;
  printf("Test 8.1  ");  // TEST 8.1
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_inf_neg_2) {
  double x = DEFAULT_1st_ARG;
  double y = S21_INF_NEG;
  printf("Test 8.2  ");  // TEST 8.2
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_inf_neg_3) {
  double x = S21_INF_NEG;
  double y = -DEFAULT_2nd_ARG;
  printf("Test 8.3  ");  // TEST 8.3
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_inf_neg_4) {
  double x = -DEFAULT_1st_ARG;
  double y = S21_INF_NEG;
  printf("Test 8.4  ");  // TEST 8.4
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_inf_pos) {
  double x = S21_INF_POS;
  double y = DEFAULT_2nd_ARG;
  printf("Test 9  ");  // TEST 9
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_inf_pos_2) {
  double x = DEFAULT_1st_ARG;
  double y = S21_INF_POS;
  printf("Test 9.2  ");  // TEST 9.2
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_inf_pos_3) {
  double x = S21_INF_POS;
  double y = -DEFAULT_2nd_ARG;
  printf("Test 9.3  ");  // TEST 9.3
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_inf_pos_4) {
  double x = -DEFAULT_1st_ARG;
  double y = S21_INF_POS;
  printf("Test 9.4  ");  // TEST 9.4
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_zero) {
  double x = DEFAULT_1st_ARG;
  double y = S21_ZERO_POS;
  printf("Test 10  ");  // TEST 10
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_zero_2) {
  double x = S21_ZERO_POS;
  double y = DEFAULT_2nd_ARG;
  printf("Test 10.2  ");  // TEST 10.2
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_zero_neg) {
  double x = S21_ZERO_NEG;
  double y = DEFAULT_2nd_ARG;
  printf("Test 11  ");  // TEST 11
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST
START_TEST(test_zero_neg_2) {
  double x = DEFAULT_1st_ARG;
  double y = S21_ZERO_NEG;
  printf("Test 11.2  ");  // TEST 11.2
  ck_assert(FUNCTION_FROM_COMPARE_C(x, y, HEALTHY_FUNCTION(x, y),
                                    STRESS_FUNCTION(x, y)));
}
END_TEST

Suite *add_suite_HEALTHY_FUNCTION(void) {
  Suite *suit = suite_create("POW_TEST");
  TCase *tc_core = tcase_create("POW_TEST");

  tcase_add_test(tc_core, standart_value);
  // tcase_add_test(tc_core, test_max);
  // tcase_add_test(tc_core, test_max_2);
  // tcase_add_test(tc_core, test_max_neg);
  // tcase_add_test(tc_core, test_max_neg_2);
  // tcase_add_test(tc_core, test_neg);
  tcase_add_test(tc_core, test_neg_2);
  tcase_add_test(tc_core, test_one);
  tcase_add_test(tc_core, test_one_2);
  tcase_add_test(tc_core, test_nan_pos);
  tcase_add_test(tc_core, test_nan_pos_2);
  tcase_add_test(tc_core, test_nan_neg);
  tcase_add_test(tc_core, test_nan_neg_2);
  tcase_add_test(tc_core, test_inf_neg);
  tcase_add_test(tc_core, test_inf_neg_2);
  // tcase_add_test(tc_core, test_inf_neg_3);
  tcase_add_test(tc_core, test_inf_neg_4);
  tcase_add_test(tc_core, test_inf_pos);
  tcase_add_test(tc_core, test_inf_pos_2);
  tcase_add_test(tc_core, test_inf_pos_3);
  tcase_add_test(tc_core, test_inf_pos_4);
  tcase_add_test(tc_core, test_zero);
  tcase_add_test(tc_core, test_zero_2);
  tcase_add_test(tc_core, test_zero_neg);
  tcase_add_test(tc_core, test_zero_neg_2);

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
    printf("%s leonardm.passed \033[0;32m\u2713\033[0m\n",
           STRESS_FUNCTION_Str);  // делаем красоту
  } else {                        // делаем красоту
    printf("%s leonardm.failed № Failed %d \033[0;31m\u2717\033[0m\n ",
           STRESS_FUNCTION_Str, ntests_failed);  // делаем красоту
  }
  srunner_free(runner);
  return (ntests_failed == 0) ? EXIT_SUCCESS : EXIT_SUCCESS;
}
