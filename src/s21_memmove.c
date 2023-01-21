#include "s21_string.h"

// Безопасно копирует n символов из src в dest
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_ptr = (unsigned char *)dest;
  unsigned char *src_ptr = (unsigned char *)src;
  char *tmp = (char *)malloc(sizeof(char) * n);
  if (tmp) {
    s21_memcpy(tmp, src_ptr, n);
    s21_memcpy(dest_ptr, tmp, n);
    free(tmp);
  }
  return dest;
}
