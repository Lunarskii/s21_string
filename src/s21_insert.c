#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result;
  s21_size_t is_error;
  s21_size_t i = 0;
  if (!src || !str || (s21_strlen(src) < start_index)) {
    is_error = 1;
  } else {
    result = calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    is_error = 0;
    for (; i < s21_strlen(src) + s21_strlen(str); i++) {
      if (i < start_index) {
        result[i] = src[i];
      }
      if (i >= start_index && i < start_index + s21_strlen(str)) {
        result[i] = str[i - start_index];
      }
      if (i >= start_index + s21_strlen(str)) {
        result[i] = src[i - s21_strlen(str)];
      }
    }
  }
  return (is_error == 0) ? result : s21_NULL;
}