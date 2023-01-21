#include "smain.h"

START_TEST(s21_memchr_test) {
  char test1[] = "123456";
  char test2 = '4';
  char test3 = '7';
  char test4[] = "hello/\0";
  char test5[] = "h";
  char test6 = 'h';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 6),
                    (unsigned long)memchr(test1, test2, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test3, 6),
                    (unsigned long)memchr(test1, test3, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test6, 6),
                    (unsigned long)memchr(test4, test6, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5, test7, 1),
                    (unsigned long)memchr(test5, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test8, 6),
                    (unsigned long)memchr(test4, test8, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test9, 6),
                    (unsigned long)memchr(test4, test9, 6));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char test1[] = "Apple Pay Money Day";
  char test2[] = "Apple with worm";
  char test3[] = "\0";
  char test4[] = "gud\0 job";
  char test5[] = "gud\0 job";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 16) < 0,
                    memcmp(test1, test2, 16) < 0);
  ck_assert_uint_eq(s21_memcmp(test1, test3, 2) > 0,
                    memcmp(test1, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test2, test3, 2) > 0,
                    memcmp(test2, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test1, 9) > 0,
                    memcmp(test4, test1, 9) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test5, 7) == 0,
                    memcmp(test4, test5, 7) == 0);
}
END_TEST

START_TEST(s21_strlen_test) {
  char test_1[] = "12345";
  char test_2[] = "Hello";
  char test_3[] = "1\0";
  char test_4[] = "   ";
  char test_5[] = "123\0456";
  char test_6[] = "hhh\0";
  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
}
END_TEST

START_TEST(s21_strcpy_test) {
  char test_1[] = "00000";
  char test_2[] = "     ";
  char test_3[] = "123\07";
  char test_4[] = "first_string\0second_string";
  char test_5[128] = "";
  char test_6[] = "Hello, world!!!";
  ck_assert_str_eq(s21_strcpy(test_1, test_2), strcpy(test_1, test_2));
  ck_assert_str_eq(s21_strcpy(test_2, test_3), strcpy(test_2, test_3));
  ck_assert_str_eq(s21_strcpy(test_4, test_5), strcpy(test_4, test_5));
  ck_assert_str_eq(s21_strcpy(test_5, test_4), strcpy(test_5, test_4));
  ck_assert_str_eq(s21_strcpy(test_6, test_5), strcpy(test_6, test_5));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char test_1[10] = "12345";
  char test_2[] = "  ";
  char test_3[20] = "///  ";
  char test_4[] = "   ///";
  char test_5[30] = "";
  char test_6[] = "4444";
  char test_7[] = "123\0123";
  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_str_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_str_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_str_eq(s21_memcpy(test_5, test_7, 6), memcpy(test_5, test_7, 6));
}
END_TEST

START_TEST(s21_strncat_test) {
  char test_2[4] = "<<<";
  char test_4[2] = "5";
  char test_44[2] = "5";
  char test_5[] = "";
  ck_assert_str_eq(s21_strncat(test_2, test_4, 1), "<<<5");
  ck_assert_str_eq(s21_strncat(test_44, test_5, 0), strncat(test_4, test_5, 0));
}
END_TEST

START_TEST(s21_strstr_test) {
  char test_1[] = "<<<5>>>";
  char test_2[] = "5";
  char test_3[] = "QwertyQwertyQwerty";
  char test_4[] = "Qwerty";
  char test_5[] = "abcd";
  char test_6[] = "";
  char test_7[] = "aaaaa123aaa1234aaa";
  char test_8[] = "1234";
  ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
  ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
  ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
  ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
  ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
}
END_TEST

START_TEST(s21_memset_test) {
  unsigned char test1[10] = "1234357890";
  unsigned char test2[10] = "hello";
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '1', 10),
                    (unsigned long)memset(test1, '1', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '3', 10),
                    (unsigned long)memchr(test1, '3', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '/', 8),
                    (unsigned long)memchr(test1, '/', 8));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '9', 0),
                    (unsigned long)memchr(test1, '9', 0));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '0', 4),
                    (unsigned long)memchr(test1, '0', 4));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, '1', 3),
                    (unsigned long)memchr(test2, '1', 3));
}
END_TEST

START_TEST(s21_strcmp_test) {
  char test1[] = "12345";
  char test2[] = "12305";
  char test3[] = "/%%5#";
  char test4[] = " @";
  char test5[] = "   ";
  char test6[] = "\\\\HH";
  ck_assert_uint_eq((unsigned long)s21_strcmp(test1, test2) > 0,
                    (unsigned long)strcmp(test1, test2) > 0);
  ck_assert_uint_eq((unsigned long)s21_strcmp(test3, test4) > 0,
                    (unsigned long)strcmp(test3, test4) > 0);
  ck_assert_uint_eq((unsigned long)s21_strcmp(test5, test6) < 0,
                    (unsigned long)strcmp(test5, test6) < 0);
}
END_TEST

START_TEST(s21_strcspn_test) {
  char test1[] = "0123456789";
  char test2[] = "9876";
  char test3[] = "LOST: 4-8-15-16-23-42";
  char test4[] = "1234567890";
  char test5[] = "0/";
  char test6[] = "%%\\#";
  char test7[] = " ";
  char test8[] = "1234567890";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_uint_eq(s21_strcspn(test3, test6), strcspn(test3, test6));
  ck_assert_uint_eq(s21_strcspn(test3, test7), strcspn(test3, test7));
  ck_assert_uint_eq(s21_strcspn(test4, test8), strcspn(test4, test8));
  ck_assert_uint_eq(s21_strcspn(test2, test7), strcspn(test2, test7));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char test1[] = "0163456769";
  char test2[] = ";;;;;;H%%//#HH";
  char test3[] = "     /";
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'H'),
                    (unsigned long)strrchr(test2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, '$'),
                    (unsigned long)strrchr(test2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
}
END_TEST

START_TEST(s21_strerror_test) {
  char *test1 = s21_strerror(0);
  char *test2 = strerror(0);
  char *test3 = s21_strerror(106);
  char *test4 = strerror(106);
  char *test5 = s21_strerror(2147483647);
  char *test6 = strerror(2147483647);
  char *test7 = s21_strerror(-214748364);
  char *test8 = strerror(-214748364);
  ck_assert_str_eq(test1, test2);
  ck_assert_str_eq(test3, test4);
  ck_assert_str_eq(test5, test6);
  ck_assert_str_eq(test7, test8);
}
END_TEST

START_TEST(s21_memmove_test) {
  char src[] = "1234567";
  char dest[] = "abcdefg";
  size_t n = 4;
  char csrc[] = "1234567";
  char cdest[] = "abcdefg";
  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(cdest, csrc, n));
  ck_assert_str_eq(dest, cdest);
  ck_assert_str_eq(dest, "1234efg");
  char dest_cover[] = "1234567";
  char *src_cover = dest_cover + 2;
  s21_memmove(dest_cover, src_cover, n);
  ck_assert_str_eq(dest_cover, "3456567");
}
END_TEST

START_TEST(s21_strchr_test) {
  char str1[] = "Abcdefg";
  int symbol1 = 'd';
  char *ach1 = s21_strchr(str1, symbol1);
  ck_assert_str_eq(ach1, "defg");
  char str2[] = "Abcdefg";
  int symbol2 = 'd';
  char *ach2 = strchr(str2, symbol2);
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(str1, str2);
  char str3[] = "Abcdefg";
  int symbol3 = '\0';
  char *ach3 = s21_strchr(str3, symbol3);
  char str4[] = "Abcdefg";
  int symbol4 = '\0';
  char *ach4 = strchr(str4, symbol4);
  ck_assert_str_eq(ach3, ach4);
  ck_assert_str_eq(str3, str4);
}
END_TEST

START_TEST(s21_strncpy_test) {
  char str1[] = "test of string";
  char dest1[15] = "";
  char str2[] = "test\0";
  char dest2[5] = "";
  char str3[] = "test ";
  char dest3[] = "crushcrush";
  ck_assert_str_eq("test ", s21_strncpy(dest1, str1, 5));
  ck_assert_str_eq("test", s21_strncpy(dest2, str2, 4));
  ck_assert_str_eq("test crush", s21_strncpy(dest3, str3, 10));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str_for_strpbrk[] = "Megalomania";
  char str_oneof[] = "yal";
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "alomania");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));
  char *str = "Hello, world";
  char *empty = "";
  ck_assert(s21_strpbrk(str, empty) == s21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "one/two/three(four)five";
  char delim1[] = "/()";
  char str_strtok2[] = "one/two/three(four)five";
  char delim2[] = "/()";
  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
  char *str1 = "\0";
  char *str2 = "\0";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str1[] = "hella 1";
  char str2[] = "hello 3";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5) < 0, strncmp(str1, str2, 5) < 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, 3) == 0,
                   strncmp(str1, str2, 3) == 0);
}
END_TEST

START_TEST(s21_strspn_test) {
  char str1[] = "hella 1";
  char str2[] = "ell";

  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(s21_strcat_test) {
  char test1[] = "Apple Pay Money Day";
  char test3[] = "\0";
  ck_assert_uint_eq((unsigned long)s21_strcat(test1, test3),
                    (unsigned long)strcat(test1, test3));
}
END_TEST

START_TEST(s21_insert_test) {
  char *src = "Hello!";
  char *str = ", world";
  char *new_str = s21_insert(src, str, 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!");
    free(new_str);
  }

  new_str = s21_insert(src, "", 15);
  ck_assert(new_str == s21_NULL);

  new_str = s21_insert("Hello!", ", world!!", 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!!!");
    free(new_str);
  }

  new_str = s21_insert("Hello!", ", world!!", 10);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello!");
    free(new_str);
  }

  new_str = s21_insert("Hello!", ", world!!", 25);
  ck_assert(new_str == s21_NULL);

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }
}
END_TEST

START_TEST(s21_trim_test) {
  char *trimmed_str;
  char *str_to_trim = " \n   Hello, world!  !\n";
  trimmed_str = s21_trim(str_to_trim, " H!\nd");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "ello, worl");
    free(trimmed_str);
  }

  char *empty_str = "";
  trimmed_str = s21_trim(empty_str, s21_NULL);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  trimmed_str = s21_trim(empty_str, " \n\0");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  char *empty_format = "";
  trimmed_str = s21_trim(str_to_trim, empty_format);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!  !");
    free(trimmed_str);
  }

  trimmed_str = s21_trim(s21_NULL, empty_format);
  ck_assert(trimmed_str == s21_NULL);

  char *str_to_trim2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  trimmed_str = s21_trim(str_to_trim2, format_str);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!");
    free(trimmed_str);
  }
}
END_TEST

START_TEST(s21_to_upper_test) {
  char str1[] = "hella hello motherfucker";
  char str2[] = "pRiVeT";

  char *new_str = s21_to_upper(str1);

  if (new_str) {
    ck_assert_str_eq(new_str, "HELLA HELLO MOTHERFUCKER");
    free(new_str);
  }

  new_str = s21_to_upper(str2);

  if (new_str) {
    ck_assert_str_eq(new_str, "PRIVET");
    free(new_str);
  }
}
END_TEST

START_TEST(s21_to_lower_test) {
  char str1[] = "hella HELLO motherfucker";
  char str2[] = "pRiVeT";
  char *new_str = s21_to_lower(str1);
  if (new_str) {
    ck_assert_str_eq(new_str, "hella hello motherfucker");
    free(new_str);
  }
  new_str = s21_to_lower(str2);
  if (new_str) {
    ck_assert_str_eq(new_str, "privet");
    free(new_str);
  }
}
END_TEST

START_TEST(s21_to_lower_test2) {
  const char *str_1 = "ADF";
  const char *str_2 = "adf";
  const char *str_3 = s21_NULL;
  const char *str_4 = "ломай меня полностью";
  char *res = s21_to_lower(str_1);
  char *res1 = s21_to_lower(str_4);
  char *res2 = s21_to_lower(str_3);
  ck_assert_str_eq(str_2, res);
  ck_assert_ptr_eq(str_3, res1);
  ck_assert_ptr_eq(str_3, res2);
  free(res);
}
END_TEST

Suite *st_20funcs(void) {
  Suite *s = suite_create("st_20funcs");
  TCase *tc1_1 = tcase_create("20funcs_tc");

  tcase_add_test(tc1_1, s21_memchr_test);
  tcase_add_test(tc1_1, s21_memcmp_test);
  tcase_add_test(tc1_1, s21_strlen_test);
  tcase_add_test(tc1_1, s21_strcpy_test);
  tcase_add_test(tc1_1, s21_memcpy_test);
  tcase_add_test(tc1_1, s21_strncat_test);
  tcase_add_test(tc1_1, s21_strstr_test);
  tcase_add_test(tc1_1, s21_memset_test);
  tcase_add_test(tc1_1, s21_strcmp_test);
  tcase_add_test(tc1_1, s21_strcspn_test);
  tcase_add_test(tc1_1, s21_strrchr_test);
  tcase_add_test(tc1_1, s21_strerror_test);
  tcase_add_test(tc1_1, s21_memmove_test);
  tcase_add_test(tc1_1, s21_strchr_test);
  tcase_add_test(tc1_1, s21_strncpy_test);
  tcase_add_test(tc1_1, s21_strpbrk_test);
  tcase_add_test(tc1_1, s21_strtok_test);
  tcase_add_test(tc1_1, s21_strncmp_test);
  tcase_add_test(tc1_1, s21_strspn_test);
  tcase_add_test(tc1_1, s21_strcat_test);

  tcase_add_test(tc1_1, s21_insert_test);
  tcase_add_test(tc1_1, s21_trim_test);
  tcase_add_test(tc1_1, s21_to_upper_test);
  tcase_add_test(tc1_1, s21_to_lower_test);
  tcase_add_test(tc1_1, s21_to_lower_test2);
  suite_add_tcase(s, tc1_1);
  return s;
}
