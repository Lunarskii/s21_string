#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *a = s21_NULL;
  if (str) {
    size_t x = s21_strlen(str);
    a = (char *)malloc((x + 1) * sizeof(char));
    s21_strcpy(a, str);
    for (size_t i = 0; i < x; i++) {
      if (a[i] >= 97 && a[i] <= 122) {
        a[i] -= 32;
      }
    }
  }
  return a;
}
