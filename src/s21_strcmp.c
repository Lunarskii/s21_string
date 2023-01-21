#include "s21_string.h"

// Сравнивает строки, на которые указывают str1 и str2
int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}
