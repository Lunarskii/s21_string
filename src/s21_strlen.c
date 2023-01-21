#include "s21_string.h"

// Вычисляет длину строки str, не включая завершающий нулевой символ
s21_size_t s21_strlen(const char *str) {
  const char *end = str;
  while (*end != '\0') ++end;
  return end - str;
}
