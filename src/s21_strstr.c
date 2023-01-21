#include "s21_string.h"

// Находит первое вхождение всей строки needle (не включая
// завершающий нулевой символ), которая появляется в строке haystack
char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;
  if (s21_strlen(haystack) >= s21_strlen(needle)) {
    for (s21_size_t i = 0; i <= s21_strlen(haystack) - s21_strlen(needle);
         i++) {
      int check = 1;
      for (s21_size_t j = i, k = 0; needle[k]; k++, j++) {
        if (haystack[j] != needle[k]) {
          check = 0;
          break;
        }
      }
      if (check) {
        res = (char *)haystack + i;
        break;
      }
    }
  }
  return res;
}
