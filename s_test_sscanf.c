#include "smain.h"

START_TEST(C_SPECIFIER) {
  char *format = "%c";
  char *string = "\n";
  char a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "      1\0";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "\0b";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  format = "%c %c %c";
  string = "1   3";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "  ";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "\\n\t";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = " sa";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "     \n     1     2\t3";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  format = "%c%c %c";
  string = "     \n     1     2\t3";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  format = "%*c%c%c %c";
  string = "123.243";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  format = "%*10c%c%c %c";
  string = "     \n     1     2\t3";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  format = "%*s %c %c %c";
  string = "     \n     1     2\t3";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  char a4 = 0, b4 = 0;
  format = "%c%c%c%c";
  string = "\\\n\t\t\t";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c%*c%c%c";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c%*2c%c%c";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c%*c%c%*c %c";
  string = "1124\n580 234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c  %c   %c    %c";
  string = "1  2   3    4";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c  %c   %c    %c";
  string = "1    2        3        4";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c %c %c %c";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c%*c%c%*c%*c%*3c%c";
  string = "sdlgk;asjgl;skadjgla;sdgjasgdakl;sdga";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 49;
  format = "%2c";
  string = "112";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(D_SPECIFIER_SHORTINT) {
  char *format = "%hd";
  char *string = "0";
  short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hd";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hd";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hd";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hd%10hd%5hd%3hd";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hd%10hd%5hd%3hd";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%1hd%hd%hd";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hd%*hd%hd%hd%*1hd%hd";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hd%1hd%1hd%1hd";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hd%5hd%9hd%1hd";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hd%*hd%1hd%1hd%*1hd%1hd";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*1hd%hd%*hd%1hd%1hd%*1hd%1hd";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*16hd%1hd%*hd%1hd%1hd%*1hd%1hd";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hd%hd%hd%3hd";
  string = "1111";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hd%hd%hd%3hd";
  string = "1111 999 888 777 389 89102 98124";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hd%3hd%3hd%3hd";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hd%1hd%1hd%3hd";
  string = "+1537 -1 +25 449";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%2hd%1hd%1hd%1hd";
  string = "+0 -0 -0 -0";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hd%3hd%3hd%3hd";
  string = "+10-10+10-10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%hd%hd%c%hd%hd";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(D_SPECIFIER_LONGINT) {
  char *format = "%ld";
  char *string = "0";
  long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%ld";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%ld";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%ld";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1ld%10ld%5ld%3ld";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1ld%10ld%5ld%3ld";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%1ld%ld%ld";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3ld%*ld%ld%ld%*1ld%ld";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1ld%1ld%1ld%1ld";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1ld%5ld%9ld%1ld";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1ld%*ld%1ld%1ld%*1ld%1ld";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*1ld%ld%*ld%1ld%1ld%*1ld%1ld";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*16ld%1ld%*ld%1ld%1ld%*1ld%1ld";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15ld%ld%ld%3ld";
  string = "1111";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15ld%ld%ld%3ld";
  string = "1111 999 888 777 389 89102 98124";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3ld%3ld%3ld%3ld";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15ld%1ld%1ld%3ld";
  string = "+1537 -1 +25 449";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%2ld%1ld%1ld%1ld";
  string = "+0 -0 -0 -0";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3ld%3ld%3ld%3ld";
  string = "+10-10+10-10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%ld%ld%c%ld%ld";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(D_SPECIFIER_INT) {
  char *format = "%d";
  char *string = "0";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%d";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%d";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%d";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1d%10d%5d%3d";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1d%10d%5d%3d";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%1d%d%d";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3d%*d%d%d%*1d%d";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1d%1d%1d%1d";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1d%5d%9d%1d";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1d%*d%1d%1d%*1d%1d";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*1d%d%*d%1d%1d%*1d%1d";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*16d%1d%*d%1d%1d%*1d%1d";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15d%d%d%3d";
  string = "1111";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15d%d%d%3d";
  string = "1111 999 888 777 389 89102 98124";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3d%3d%3d%3d";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15d%1d%1d%3d";
  string = "+1537 -1 +25 449";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%2d%1d%1d%1d";
  string = "+0 -0 -0 -0";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3d%3d%3d%3d";
  string = "+10-10+10-10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%d%d%c%d%d";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(U_SPECIFIER_SHORTINT) {
  char *format = "%hu";
  char *string = "0";
  unsigned short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                     b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hu";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hu";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hu";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%1hu%hu%hu";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%*hu%hu%hu%*1hu%hu";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%1hu%1hu%1hu";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%5hu%9hu%1hu";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%*hu%1hu%1hu%*1hu%1hu";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*1hu%hu%*hu%1hu%1hu%*1hu%1hu";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*16hu%1hu%*hu%1hu%1hu%*1hu%1hu";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%hu%hu%3hu";
  string = "1111";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%hu%hu%3hu";
  string = "1111 999 888 777 389 89102 98124";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%1hu%1hu%3hu";
  string = "+1537 -1 +25 449";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%2hu%1hu%1hu%1hu";
  string = "+0 -0 -0 -0";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "+10-10+10-10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%hu%hu%c%hu%hu";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_uint_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(U_SPECIFIER_LONGINT) {
  char *format = "%lu";
  char *string = "0";
  unsigned long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                    b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%lu";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%lu";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%lu";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%1hu%lu%lu";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%*lu%lu%lu%*1hu%lu";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%1hu%1hu%1hu";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%5hu%9hu%1hu";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%*lu%1hu%1hu%*1hu%1hu";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*1hu%lu%*lu%1hu%1hu%*1hu%1hu";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*16hu%1hu%*lu%1hu%1hu%*1hu%1hu";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%lu%lu%3hu";
  string = "1111";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%lu%lu%3hu";
  string = "1111 999 888 777 389 89102 98124";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%1hu%1hu%3hu";
  string = "+1537 -1 +25 449";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%2hu%1hu%1hu%1hu";
  string = "+0 -0 -0 -0";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "+10-10+10-10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%lu%lu%c%lu%lu";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_uint_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(U_SPECIFIER_INT) {
  char *format = "%u";
  char *string = "0";
  unsigned int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%u";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%u";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%u";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%1hu%u%u";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%*u%u%u%*1hu%u";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%1hu%1hu%1hu";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%5hu%9hu%1hu";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%*u%1hu%1hu%*1hu%1hu";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*1hu%u%*u%1hu%1hu%*1hu%1hu";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*16hu%1hu%*u%1hu%1hu%*1hu%1hu";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%u%u%3hu";
  string = "1111";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%u%u%3hu";
  string = "1111 999 888 777 389 89102 98124";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%1hu%1hu%3hu";
  string = "+1537 -1 +25 449";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%2hu%1hu%1hu%1hu";
  string = "+0 -0 -0 -0";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "+10-10+10-10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%u%u%c%u%u";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_uint_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_SHORTINT) {
  char *format = "%hi";
  char *string = "0";
  short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hi";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hi";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hi";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hlli%10hlli%5hlli%3hlli";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%1hlli%hi%hi";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hlli%3hlli%3hlli%3hlli";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%hi%hi%c%hi%hi";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_LONGINT) {
  char *format = "%li";
  char *string = "0";
  long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%li";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%li";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%li";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hlli%10hlli%5hlli%3hlli";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%1hlli%li%li";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hlli%3hlli%3hlli%3hlli";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%li%li%c%li%li";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_INT) {
  char *format = "%i";
  char *string = "0";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%i";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%i";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%i";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hlli%10hlli%5hlli%3hlli";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%1hlli%i%i";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hlli%3hlli%3hlli%3hlli";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%i%i%c%i%i";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*i   %*i %*i%*6i";
  string = "0x10 125 012 0x125";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_HEX) {
  char *format = "%i%i%i%i";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%i%i%i%i";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%1i%1i";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %i %*i %i";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "-a +b -cdef -fff";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "-0xf +0x1 -e -eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_SHORTHEX) {
  char *format = "%hi%hi%hi%hi";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%hi%hi%hi%hi";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%1i%1i";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0X 2X 3X 4X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%hi%hi%hi%hi";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %hi %*i %hi";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "-a +b -cdef -fff";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "-0xf +0x1 -e -eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_LONGHEX) {
  char *format = "%li%li%li%li";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%li%li%li%li";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%1i%1i";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0X 2X 3X 4X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%li%li%li%li";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %li %*i %li";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "-a +b -cdef -fff";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "-0xf +0x1 -e -eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_OCT) {
  char *format = "%i%i%i%i";
  char *string = "";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x7777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0X 0X 0X 0X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4i%4i%1i%4i";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o%i%i%*o%i%i";
  string = "0x100x200x300x40 0x10 0x30 0x52 0x48";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "a b c d e f";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "-0x120 +0x10 -0x15 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_SHORTOCT) {
  char *format = "%hi%hi%hi%hi";
  char *string = "";
  short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0x7777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0X 0X 0X 0X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4hi%4hi%1hi%4hi";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o%hi%hi%*o%hi%hi";
  string = "0x100x200x300x40 0x10 0x30 0x52 0x48";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "a b c d e f";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "-0x120 +0x10 -0x15 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_LONGOCT) {
  char *format = "%li%li%li%li";
  char *string = "";
  long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0x7777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0X 0X 0X 0X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4li%4li%1li%4li";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o%li%li%*o%li%li";
  string = "0x100x200x300x40 0x10 0x30 0x52 0x48";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "a b c d e f";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "-0x120 +0x10 -0x15 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_COMBINATIONS) {
  char *format = "%i%i%i%i";
  char *string = "012 335 0x123 558";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(G_SPECIFIER_FLOAT) {
  char *format = "%g%g%g%g";
  char *string = "1.2 2.4 3.6 4.8";
  float a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "1.2 2.4 3.6 4.8";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "0.0000001 -1 2.5 .1 125";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = ". . . .";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*g%g%g%*2g%g%g";
  string = "1.2 2.4 3.6 4.8 6.0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "1.2e+4 2.4e-4 3.6e4 0.1388882e+7";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "1.2 2.4 3.6 4.8";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "2ee4 2.3e++10 2.5e--10 --+";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "2.5e+3 ++ -- ++";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = ".1 +.2 -.3 ..4";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "1. 2. 3. 4.";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2g%10g%6g%1g";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%1g%1g%1g%1g";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2g%3g%5g%10g";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%15g%3g%6g%2g";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string = "2.5e+500";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_float_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string =
      "12849812851."
      "125812957120951829351239501827351023827601239854791203958127859123895012"
      "37512835127351238950871235709123587127385912938502173519280357891235e-4";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_float_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string =
      "999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999e+30";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_float_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "nan -nan inf -inf";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_float_infinite(a3);
  ck_assert_float_infinite(a4);
  ck_assert_float_nan(b1);
  ck_assert_float_nan(b2);
  ck_assert_float_infinite(b3);
  ck_assert_float_infinite(b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(G_SPECIFIER_DOUBLE) {
  char *format = "%lg%lg%lg%lg";
  char *string = "1.2 2.4 3.6 4.8";
  double a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "1.2 2.4 3.6 4.8";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "0.0000001 -1 2.5 .1 125";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = ". . . .";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*lg%lg%lg%*2lg%lg%lg";
  string = "1.2 2.4 3.6 4.8 6.0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "1.2e+4 2.4e-4 3.6e4 0.182e+7";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "1.2 2.4 3.6 4.8";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "2ee4 2.3e++10 2.5e--10 --+";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "2.5e+3 ++ -- ++";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = ".1 +.2 -.2 ..4";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "1. 2. 3. 4.";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2lg%10lg%6lg%1lg";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%1lg%1lg%1lg%1lg";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2lg%3lg%5lg%10lg";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%15lg%3lg%6lg%2lg";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string = "2.5e+500";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_double_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string =
      "12849812851."
      "125812957120951829351239501827351023827601239854791203958127859123895012"
      "37512835127351238950871235709123587127385912938502173519280357891235e-4";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_double_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string =
      "999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999e+30";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_double_eq(a1, b1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(G_SPECIFIER_LONGDOUBLE) {
  char *format = "%Lg%Lg%Lg%Lg";
  char *string = "1.5 2.5 3.5 4.5";
  long double a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "1.5 2.5 3.5 4.5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "3.5 -1 2.5 .5 125";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = ". . . .";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*Lg%Lg%Lg%*2Lg%Lg%Lg";
  string = "1.5 2.5 3.5 4.5 6.0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "1.5e+4 5 3.5e4 4.5e";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "1.5 2.5 3.5 4.5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "2ee4 2.3e++10 2.5e--10 --+";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "2.5e+3 ++ -- ++";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = ".5 +.5 -.5 ..5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "1. 2. 3. 4.";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2Lg%10Lg%6Lg%1Lg";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%1Lg%1Lg%1Lg%1Lg";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2Lg%3Lg%5Lg%10Lg";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%15Lg%3Lg%6Lg%2Lg";
  string = "-e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string = "2.5e+500";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string =
      "12849812851."
      "125812957120951829351239501827351023827601239854791203958127859123895012"
      "37512835127351238950871235709123587127385912938502173519280357891235e-4";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string =
      "999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999e+30";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(O_SPECIFIER_USHORTOCT) {
  char *format = "%ho%ho%ho%ho";
  char *string = "";
  unsigned short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                     b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0x77777777777777777777777777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0X 0X 0X 0X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4ho%4ho%1ho%4ho";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o%ho%ho%*o%ho%ho";
  string = "0x100x200x300x40 0x10 0x30 0x52 0x48";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "a b c d e f";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "-0x120 +0x10 -0x15 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(O_SPECIFIER_ULONGOCT) {
  char *format = "%lo%lo%lo%lo";
  char *string = "";
  long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0x77777777777777777777777777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0X 0X 0X 0X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4lo%4lo%1lo%4lo";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o%lo%lo%*o%lo%lo";
  string = "0x100x200x300x40 0x10 0x30 0x52 0x48";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "a b c d e f";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "-0x120 +0x10 -0x15 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(O_SPECIFIER_UOCT) {
  char *format = "%o%o%o%o";
  char *string = "";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0x77777777777777777777777777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0X 0X 0X 0X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4o%4o%1o%4o";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o%o%o%*o%o%o";
  string = "0x100x200x300x40 0x10 0x30 0x52 0x48";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "a b c d e f";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "-0x120 +0x10 -0x15 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER1) {
  char *format = "%s %s %s %s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER2) {
  char *format = "%s%s%s%s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER3) {
  char *format = "%s   %s     %s     %s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER4) {
  char *format = "%s%s%s%s";
  char *string = "string1\nstring2 string3\tstr\0ing4string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER5) {
  char *format = "%s%*s%s  %*s %s%s %*s";
  char *string =
      "string1 string2 string3 string4 string5 string6 string7 string8 string9 "
      "string10";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER6) {
  char *format = "%s%*s%s%s  %*s%s    %*s";
  char *string = "1 2 3 4 5 6 7 8";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER7) {
  char *format = "%1s%2s%3s%4s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER8) {
  char *format = "%4s%3s%2s%1s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER9) {
  char *format = "%s%*3s%s%*6s%s%s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER10) {
  char *format = "%1s%1s%1s%1s";
  char *string =
      "string1 string2 string3 string4 string5 string7 string8 string9 "
      "string10";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER11) {
  char *format = "%10s%15s%20s%30s";
  char *string =
      "string1\tstring2\nstring3      string4\0string5 string7 string8 string9 "
      "string10";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER12) {
  char *format = "%100s%200s%300s%400s";
  char *string =
      "string1 string2 string3 string4 string5 string7 string8 string9 "
      "string10";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(X_SPECIFIER_USHORTHEX) {
  char *format = "%hx%hx%hx%hx";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  unsigned short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                     b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  // ck_assert_int_eq(a2, b2);
  // ck_assert_int_eq(a3, b3);
  // ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%1i%1i";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "0X 2X 3X 4X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%hx%hx%hx%hx";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %hx %*i %hx";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "-a +b -cdef -fff";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "-0xf +0x1 -e -eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(X_SPECIFIER_ULONGHEX) {
  char *format = "%lx%lx%lx%lx";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  unsigned long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                    b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%lx%lx%lx%lx";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%1i%1i";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "0X 2X 3X 4X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%lx%lx%lx%lx";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %lx %*i %lx";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "-a +b -cdef -fff";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "-0xf +0x1 -e -eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(X_SPECIFIER_UHEX) {
  char *format = "%x%x%x%x";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  unsigned int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%x%x%x%x";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%1i%1i";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "0X 2X 3X 4X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%x%x%x%x";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %x %*i %x";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "-a +b -cdef -fff";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "-0xf +0x1 -e -eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x%*x%*x    %*x";
  string = "0xf 0x1 0x 0x123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(P_SPECIFIER1) {
  char *format = "%p%p%p%p";
  char *string = "0x123 0xAAAA 0xffffFFFFffff 0x9821238 9x123";
  int *a1 = 0, *a2 = 0, *a3 = 0, *a4 = 0, *b1 = 0, *b2 = 0, *b3 = 0, *b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ptr_eq(a1, b1);
  ck_assert_ptr_eq(a2, b2);
  ck_assert_ptr_eq(a3, b3);
  ck_assert_ptr_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(P_SPECIFIER2) {
  char *format = "%p%p%p%p";
  char *string = "0x1 0x2 0x3 0x4 0x5 0x6";
  int *a1 = 0, *a2 = 0, *a3 = 0, *a4 = 0, *b1 = 0, *b2 = 0, *b3 = 0, *b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ptr_eq(a1, b1);
  ck_assert_ptr_eq(a2, b2);
  ck_assert_ptr_eq(a3, b3);
  ck_assert_ptr_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(P_SPECIFIER3) {
  char *format = "%p%p%p%p";
  char *string = "+12 -99 +128 -33 55";
  int *a1 = 0, *a2 = 0, *a3 = 0, *a4 = 0, *b1 = 0, *b2 = 0, *b3 = 0, *b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ptr_eq(a1, b1);
  ck_assert_ptr_eq(a2, b2);
  ck_assert_ptr_eq(a3, b3);
  ck_assert_ptr_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(P_SPECIFIER4) {
  char *format = "%p%p%p%p";
  char *string = "015 016 017 -018";
  int *a1 = 0, *a2 = 0, *a3 = 0, *a4 = 0, *b1 = 0, *b2 = 0, *b3 = 0, *b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ptr_eq(a1, b1);
  ck_assert_ptr_eq(a2, b2);
  ck_assert_ptr_eq(a3, b3);
  ck_assert_ptr_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(N_SPECIFIER) {
  char *format = "%d%d%n%d%d%n";
  char *string = "12 345 67 891 0 92 1 2 3 84 8 5 5423 134 464 ";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &n1, &a3, &a4, &n2);
  int res2 = sscanf(string, format, &b1, &b2, &n3, &b3, &b4, &n4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(n1, n3);
  ck_assert_int_eq(n2, n4);
  ck_assert_int_eq(res1, res2);

  format = "%s %s      %n  %s    %s";
  string = "slkdgfsd jgdsla;gk as;ldg jasd;gl kasdjg ;alsdg jasgds";
  n1 = 0, n2 = 0;
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  res1 = s21_sscanf(string, format, string1, string2, &n1, string3, string4);
  res2 = sscanf(string, format, string5, string6, &n2, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);

  format = "%n";
  string = "sd56fk. sj12ggdflk -sdjfk+123 sjkdl fd";
  n1 = 0, n2 = 0;
  res1 = s21_sscanf(string, format, &n1);
  res2 = sscanf(string, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);

  format = "   %c%n  %c %c    %n%c";
  string = "sdlkf sdf bv81 2k 283 mkals98f 123    as";
  n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  char c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0;
  res1 = s21_sscanf(string, format, &c1, &n1, &c2, &c3, &n2, &c4);
  res2 = sscanf(string, format, &c5, &n3, &c6, &c7, &n4, &c8);
  ck_assert_int_eq(c1, c5);
  ck_assert_int_eq(c2, c6);
  ck_assert_int_eq(c3, c7);
  ck_assert_int_eq(c4, c8);
  ck_assert_int_eq(n1, n3);
  ck_assert_int_eq(n2, n4);
  ck_assert_int_eq(res1, res2);

  int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
  short int q1, q2;
  long int q3, q4;
  format = "%d%ln%d%hn";
  string = "128948 0124 8190284";
  res1 = s21_sscanf(string, format, &v1, &q3, &v3, &q1);
  res2 = sscanf(string, format, &v2, &q4, &v4, &q2);
  ck_assert_int_eq(v1, v2);
  ck_assert_int_eq(q3, q4);
  ck_assert_int_eq(v3, v4);
  ck_assert_int_eq(q1, q2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(PERCENT_SPECIFIER) {
  char *format = "%d%%%d%d%%%d";
  char *string = "125 % 389 92 % % 10";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%d%%%d%d%%%d";
  string = "10%20 30% 125 98";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%%%%%%%%%%%d%%%d%d%%%d";
  string = "%%%%%125 % 389 92 % % 10";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%%%%";
  string = "%%";
  res1 = s21_sscanf(string, format, 0);
  res2 = sscanf(string, format, 0);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *st_sscanf(void) {
  Suite *s = suite_create("st_sscanf");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, C_SPECIFIER);
  tcase_add_test(tc, D_SPECIFIER_SHORTINT);
  tcase_add_test(tc, D_SPECIFIER_LONGINT);
  tcase_add_test(tc, D_SPECIFIER_INT);
  tcase_add_test(tc, U_SPECIFIER_SHORTINT);
  tcase_add_test(tc, U_SPECIFIER_LONGINT);
  tcase_add_test(tc, U_SPECIFIER_INT);
  tcase_add_test(tc, I_SPECIFIER_SHORTINT);
  tcase_add_test(tc, I_SPECIFIER_LONGINT);
  tcase_add_test(tc, I_SPECIFIER_INT);
  tcase_add_test(tc, I_SPECIFIER_HEX);
  tcase_add_test(tc, I_SPECIFIER_SHORTHEX);
  tcase_add_test(tc, I_SPECIFIER_LONGHEX);
  tcase_add_test(tc, I_SPECIFIER_OCT);
  tcase_add_test(tc, I_SPECIFIER_SHORTOCT);
  tcase_add_test(tc, I_SPECIFIER_LONGOCT);
  tcase_add_test(tc, I_SPECIFIER_COMBINATIONS);
  tcase_add_test(tc, G_SPECIFIER_FLOAT);
  tcase_add_test(tc, G_SPECIFIER_DOUBLE);
  tcase_add_test(tc, G_SPECIFIER_LONGDOUBLE);
  tcase_add_test(tc, O_SPECIFIER_USHORTOCT);
  tcase_add_test(tc, O_SPECIFIER_ULONGOCT);
  tcase_add_test(tc, O_SPECIFIER_UOCT);
  tcase_add_test(tc, S_SPECIFIER1);
  tcase_add_test(tc, S_SPECIFIER2);
  tcase_add_test(tc, S_SPECIFIER3);
  tcase_add_test(tc, S_SPECIFIER4);
  tcase_add_test(tc, S_SPECIFIER5);
  tcase_add_test(tc, S_SPECIFIER6);
  tcase_add_test(tc, S_SPECIFIER7);
  tcase_add_test(tc, S_SPECIFIER8);
  tcase_add_test(tc, S_SPECIFIER9);
  tcase_add_test(tc, S_SPECIFIER10);
  tcase_add_test(tc, S_SPECIFIER11);
  tcase_add_test(tc, S_SPECIFIER12);
  tcase_add_test(tc, X_SPECIFIER_USHORTHEX);
  tcase_add_test(tc, X_SPECIFIER_ULONGHEX);
  tcase_add_test(tc, X_SPECIFIER_UHEX);
  tcase_add_test(tc, P_SPECIFIER1);
  tcase_add_test(tc, P_SPECIFIER2);
  tcase_add_test(tc, P_SPECIFIER3);
  tcase_add_test(tc, P_SPECIFIER4);
  tcase_add_test(tc, N_SPECIFIER);
  tcase_add_test(tc, PERCENT_SPECIFIER);

  suite_add_tcase(s, tc);
  return s;
}
