#include "s21_string.h"

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
  int len = s21_strlen(str);
  char *res = s21_NULL;

  for (int x = len; res == s21_NULL && x >= 0; x -= 1) {
    if (str[x] == c) res = (char *)str + x;
  }

  return (char *)res;
}
