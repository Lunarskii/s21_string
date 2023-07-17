#include <check.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

Suite *st_sprintf(void);
Suite *st_sscanf(void);
Suite *st_20funcs(void);
// int s21_sprintf(char *str, const char *format, ...);
// int s21_sscanf(const char *str, const char *format, ...)
//     __attribute__((format(scanf, 2, 3)));