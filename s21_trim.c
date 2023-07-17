#include "s21_string.h"

void delete_first_letter(char *str) {
  s21_size_t counter = 0;
  while (str[counter]) {
    str[counter] = str[counter + 1];
    counter++;
  }
}

void rightpart(char *str_trim, const char *src, const char *trim_chars) {
  s21_size_t trim_lenght = s21_strlen(trim_chars);
  s21_size_t str_trim_length = s21_strlen(str_trim);
  for (int i = (int)str_trim_length - 1; i >= 0; i--) {
    int is_break = 0;
    for (s21_size_t j = 0; j < trim_lenght; j++) {
      if (str_trim[i] == trim_chars[j]) {
        str_trim[i] = '\0';
        break;
      }
      if (j == trim_lenght - 1 && src[i] != trim_chars[trim_lenght]) {
        is_break = 1;
      }
    }
    if (is_break) break;
  }
}

void leftpart(char *str_trim, const char *src, const char *trim_chars) {
  s21_size_t trim_lenght = s21_strlen(trim_chars);
  s21_size_t str_length = s21_strlen(src);
  for (s21_size_t i = 0; i < str_length; i++) {
    int is_break = 0;
    for (s21_size_t j = 0; j < trim_lenght; j++) {
      if (src[i] == trim_chars[j]) {
        delete_first_letter(str_trim);
        break;
      }
      if (j == trim_lenght - 1 && src[i] != trim_chars[trim_lenght]) {
        is_break = 1;
      }
    }
    if (is_break) break;
  }
}

void *s21_trim(const char *src, const char *trim_chars) {
  int error_flag = 0;
  char *str_trim = s21_NULL;
  if (src) {
    char default_chars[10] = " \t\n\v\r\f\0";
    if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0)
      trim_chars = default_chars;
    str_trim = (char *)malloc((s21_strlen(src) + 10) * sizeof(char));
    if (str_trim == s21_NULL) {
      error_flag = 1;
    } else {
      s21_strcpy(str_trim, (char *)src);
      leftpart(str_trim, src, trim_chars);
      rightpart(str_trim, src, trim_chars);
    }
  } else {
    error_flag = 1;
  }
  return error_flag ? s21_NULL : (void *)str_trim;
}
