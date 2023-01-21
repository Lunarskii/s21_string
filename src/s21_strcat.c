#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest
char *s21_strcat(char *dest, const char *src) {
  s21_strcpy(dest + s21_strlen(dest), src);
  return dest;
}
