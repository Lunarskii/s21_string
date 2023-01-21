#include "s21_string.h"

// Копирует строку, на которую указывает src, в dest
char *s21_strcpy(char *dest, const char *src) {
  return s21_memcpy(dest, src, s21_strlen(src) + 1);
}
