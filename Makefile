TARGET = s21_string
LIBRARY = s21_string.a
FLAG_COV = --coverage
CC = gcc 
FLAGS = -Wall -Werror -Wextra -std=c11
OS=$(shell uname)

ifeq (${OS}, Linux)
      TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
      TEST_FLAGS = -lcheck -lm
endif
GCOV=-fprofile-arcs -ftest-coverage -fPIC
#CHECK:=$(shell pkg-config --cflags --libs check)
SRC = $(wildcard s21_*.c) 
OBJ_TEST=s_test_sscanf.o s_test_sprintf.o test_func.o
OBJ = $(patsubst %.c, %.o, $(SRC))

all: test

$(TARGET) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(TARGET)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBRARY): $(SRC)
#	$(CC) -c $(SRC)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(LIBRARY) $(OBJ)
	ranlib $(LIBRARY) 

test_func.o: test_func.c
	gcc -c test_func.c

s_test_sscanf.o: s_test_sscanf.c
	gcc -c s_test_sscanf.c

s_test_sprintf.o: s_test_sprintf.c
	gcc -c s_test_sprintf.c

smain.o: smain.c
	gcc $(FLAGS) -c smain.c

clean:
	rm -rf $(TARGET)
	rm -rf test
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcda
	rm -rf report
	rm -rf *.gcno
	rm -rf *.info

test: $(LIBRARY) smain.o $(OBJ_TEST)
#	$(CC) $(GCOV) smain.o $(OBJ_TEST) -o test s21_string.a $(TEST_FLAGS)
	$(CC) $(FLAGS) $(GCOV) smain.o $(OBJ_TEST) -o test s21_string.a $(TEST_FLAGS)
	./test

open: 
	open report/index.html
    
gcov_report: clean $(OBJ_TEST) smain.o
#	$(CC) -o test $(OBJ_TEST) smain.o $(FLAG_COV) s21*.c $(TEST_FLAGS)
	$(CC) $(FLAGS) -o test $(OBJ_TEST) smain.o $(FLAG_COV) s21*.c $(TEST_FLAGS)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	make open

.PHONY: all clean open
