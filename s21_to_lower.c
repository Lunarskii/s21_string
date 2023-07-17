#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *result;
  if (str == s21_NULL) {
    result = s21_NULL;
  } else {
    result = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
      if ((str[i] > 64 && str[i] < 91) && result != s21_NULL) {
        result[i] = str[i] + 32;
      } else if ((str[i] >= 0 && str[i] < 127) && result != s21_NULL) {
        result[i] = str[i];
      } else {
        result = s21_NULL;
      }
    }
  }
  return result;
}