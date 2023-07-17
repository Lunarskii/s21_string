#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t len = s21_strlen(dest);
  s21_size_t i;
  for (i = 0; i < n && src[i]; i++) dest[len + i] = src[i];
  dest[len + i] = '\0';
  return dest;
}
