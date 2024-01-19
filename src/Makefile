CC = gcc
FLAGS = -Wall -Werror -Wextra --std=c11 --pedantic
LIBS = -lcheck -lsubunit -lm -lgcov
FUNC_FILES_C = *.c
FUNC_FILES_O = *.o
CHECKFLAGS = $(shell pkg-config --cflags --libs check)
GCOVFLAGS = --coverage
LIBNAME = s21_math.a

test_path = tests/
func_path = functions/

all: s21_math.a

build_object_files:
	$(CC) $(FLAGS) -c $(func_path)$(FUNC_FILES_C)

build_library: build_object_files
	ar rcs $(LIBNAME) $(FUNC_FILES_O)
	rm -rf *.o

s21_math.a: build_library

build_object_files1:
	$(CC) $(FLAGS) $(GCOVFLAGS) -c $(func_path)$(FUNC_FILES_C)

build_library1: build_object_files1
	ar rcs $(LIBNAME) $(FUNC_FILES_O)
	rm -rf *.o

compile_tests: build_library1
	$(CC) $(test_path)s21_test_abs.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_abs_test
	$(CC) $(test_path)s21_test_acos.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_acos_test
	$(CC) $(test_path)s21_test_asin.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_asin_test
	$(CC) $(test_path)s21_test_atan.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_atan_test
	$(CC) $(test_path)s21_test_ceil.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_ceil_test
	$(CC) $(test_path)s21_test_cos.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_cos_test
	$(CC) $(test_path)s21_test_exp.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_exp_test
	$(CC) $(test_path)s21_test_fabs.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_fabs_test
	$(CC) $(test_path)s21_test_floor.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_floor_test
	$(CC) $(test_path)s21_test_fmod.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_fmod_test
	$(CC) $(test_path)s21_test_log.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_log_test
	$(CC) $(test_path)s21_test_pow.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_pow_test
	$(CC) $(test_path)s21_test_sin.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_sin_test
	$(CC) $(test_path)s21_test_sqrt.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_sqrt_test
	$(CC) $(test_path)s21_test_tan.c -L. s21_math.a $(CHECKFLAGS)  $(GCOVFLAGS) -o s21_tan_test

st: clean
	make -s -i test | grep "leonardm\|monroebu\|tilmapat" #-i не останавливает вып команд после ошибки, #-s silent
	make -s clean


test: compile_tests
	./s21_abs_test
	./s21_acos_test
	./s21_asin_test
	./s21_atan_test
	./s21_ceil_test
	./s21_cos_test
	./s21_exp_test
	./s21_fabs_test
	./s21_floor_test
	./s21_fmod_test
	./s21_log_test
	./s21_pow_test
	./s21_sin_test
	./s21_sqrt_test
	./s21_tan_test
	

gcov_report: clean  test
	gcov *.gcno
	gcovr -r . --html --html-details -o s21_math.html
	open s21_math.html

# gcov_report: clean test
# 	gcov $(FUNC_FILES_C)
# 	~/.local/bin/gcovr -r . --html --html-details -o s21_math.html

	
gcov: gcov_report
	@echo "Opening report..." 
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.a

clean:
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.a
	rm -f *.info
	rm -f *.html
	rm -f *.css
	rm -f s21_*_test

.PHONY: cl
cl:
	clear
	clang-format -n -style=Google *.c *.h | true
	clang-format -n -style=Google $(test_path)*.c *.h | true
	clang-format -n -style=Google $(func_path)*.c *.h | true
	clang-format -i -style=Google *.c *.h | true
	clang-format -i -style=Google $(test_path)*.c *.h | true
	clang-format -i -style=Google $(func_path)*.c *.h | true	

.PHONY: cpp
cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c11 *.c $(func_path)/*.c
#	cppcheck --enable=all --suppress=missingIncludeSystem --std=c11 *.c $(test_path)/*.c
# cppcheck *.c $(func_path)/*.c

tpow:compile_tests
	./s21_pow_test

tsqrt:compile_tests
	./s21_sqrt_test

tlog:compile_tests
	./s21_log_test

texp:compile_tests
	./s21_exp_test

tabs:compile_tests
	./s21_abs_test

tceil:compile_tests
	./s21_ceil_test

tfabs:compile_tests
	./s21_fabs_test

tfloor:compile_tests
	./s21_floor_test

tfmod:compile_tests
	./s21_fmod_test
	