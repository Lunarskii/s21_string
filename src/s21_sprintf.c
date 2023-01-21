#include "s21_sprintf.h"

// structure of current symb number and specifier string

struct flags {
  int flag_minus;  // in the end
  int flag_plus;   //
  int flag_space;  //
  int flag_hashtag;
  int flag_null;      // in the end
  int width_num;      // in the end
  int width_star;     // done
  int accuracy_num;   // -1 = default default value
  int accuracy_star;  // done
  int len_h;
  int len_l;
  int len_L;
};

int atoi_m(char s[11]) {
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) n = 10 * n + (s[i] - '0');
  return n;
}

long pow_m(int x, int y) {  // cutted version of pow from math.h
  long result = 1;
  while (y > 0) {
    result *= x;
    y--;
  }
  return result;
}

struct flags flag_parser(char *flag_str, int flag_len) {
  struct flags f_i = {0};
  f_i.accuracy_num = -1;
  for (int i = 0; i < flag_len; i++) {
    switch (flag_str[i]) {
      case '-':
        f_i.flag_minus = 1;
        break;
      case '+':
        f_i.flag_plus = 1;
        break;
      case ' ':
        f_i.flag_space = 1;
        break;
      case '#':
        f_i.flag_hashtag = 1;
        break;
      case '0':
        f_i.flag_null = 1;
        break;
      case '*':  // (number) will be default case
        f_i.width_star = 1;
        break;
      case '.':
        if (flag_str[i + 1] >= '0' && flag_str[i + 1] <= '9') {
          i++;
          char num_str[11] = {0};
          int num_count = 0;
          while (flag_str[i] >= '0' && flag_str[i] <= '9') {
            num_str[num_count] = flag_str[i];
            num_count++;
            i++;
          }
          i--;
          f_i.accuracy_num = atoi_m(num_str);  // atoi!!
        } else {
          if (flag_str[i + 1] == '*') {
            f_i.accuracy_star = 1;
            i++;
          } else {                 // for example "%.d"
            f_i.accuracy_num = 0;  // default value
          }
        }
        break;
      case 'h':
        f_i.len_h = 1;
        break;
      case 'l':
        f_i.len_l = 1;
        break;
      case 'L':
        f_i.len_L = 1;
        break;
      default:
        if (flag_str[i] >= '0' && flag_str[i] <= '9') {
          char num_str[11] = {0};
          int num_count = 0;
          while (flag_str[i] >= '0' && flag_str[i] <= '9') {
            num_str[num_count] = flag_str[i];
            num_count++;
            i++;
          }
          i--;
          f_i.width_num = atoi_m(num_str);
        } else {
          i++;
        }
    }
  }
  free(flag_str);
  return f_i;
}

// all specifiers functions return str that we cat with main str

void reverse_str(char *str) {
  int i, len, temp;
  len = s21_strlen(str);
  for (i = 0; i < len / 2; i++) {
    temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }

  return;
}

char *itoa(int num, char *str, struct flags f_i) {
  int i = 0;
  int sign = 1;
  if (num < 0) {
    sign = -1;
    num = -num;
  }
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  if (!(f_i.accuracy_num == 0 && num == 0)) {
    do {
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = num % 10 + 48;
      num /= 10;
    } while (num > 0);
  }
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  if (sign < 0) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '-';
  } else if (f_i.flag_plus == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '+';
  } else if (f_i.flag_space == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = ' ';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *d_specifier(struct flags f_i, int argument) {
  char *str = (char *)malloc(sizeof(char) * 20);
  str = itoa(argument, str, f_i);
  return str;
}

char *h_itoa(short num, char *str, struct flags f_i) {
  int i = 0;
  int sign = 1;
  if (num < 0) {
    sign = -1;
    num = -num;
  }
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  if (!(f_i.accuracy_num == 0 && num == 0)) {
    do {
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = num % 10 + 48;
      num /= 10;
    } while (num > 0);
  }
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  if (sign < 0) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '-';
  } else if (f_i.flag_plus == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '+';
  } else if (f_i.flag_space == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = ' ';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *hd_specifier(struct flags f_i, short argument) {
  char *str = (char *)malloc(sizeof(char) * 20);
  str = h_itoa(argument, str, f_i);
  return str;
}

char *l_itoa(long int num, char *str, struct flags f_i) {
  int i = 0;
  int sign = 1;
  if (num < 0) {
    sign = -1;
    num = -num;
  }
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  if (!(f_i.accuracy_num == 0 && num == 0)) {
    do {
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = num % 10 + 48;
      num /= 10;
    } while (num > 0);
  }
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  if (sign < 0) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '-';
  } else if (f_i.flag_plus == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '+';
  } else if (f_i.flag_space == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = ' ';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *ld_specifier(struct flags f_i, long int argument) {
  char *str = (char *)malloc(sizeof(char) * 20);
  str = l_itoa(argument, str, f_i);
  return str;
}

char *itoa_exp(double num, struct flags f_i, char specifier) {
  int i = 0;
  int pow_count = 0;
  char *str = (char *)malloc(sizeof(char));
  int sign = 1;
  int is_zero = 0;
  if (num == 0.0) {
    is_zero = 1;
  }
  if (num < 0) {
    sign = -1;
    num = -num;
  }
  //  -0.0012003 = -1.200300e-03
  // 120.0025 = 1.200025e+02
  if (num < 1 && is_zero == 0) {
    do {
      num *= 10;
      pow_count--;
    } while (num < 1);
  } else if (num > 10) {
    do {
      num /= 10;
      pow_count++;
    } while (num > 10);
  }
  long integer_part = (long)num;
  double float_part = num - (double)integer_part;
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 6;  // 0.12345
  }
  if (specifier == 'g' || specifier == 'G') {
    if (integer_part != 0) {
      f_i.accuracy_num--;
    }
  }
  if (f_i.accuracy_num != 0) {
    for (int j = 0; j < f_i.accuracy_num; j++) {  //   1.00001 false result
      float_part *= 10;
    }
    long current_part =
        (long)(float_part + 0.5);  // for successful round    check 1.9999996
    long powed = pow_m(10, f_i.accuracy_num);
    if (current_part >= powed) {
      current_part = current_part - powed;
      integer_part++;
      // printf("my %c %ld\n", specifier, integer_part);
      if (integer_part >= 10) {
        integer_part /= 10;
        pow_count++;
      }
    }

    int pow_sign = 1;
    if (pow_count < 0) {
      pow_sign = -1;
      pow_count = -pow_count;
    }
    if (pow_count < 10) {
      str = (char *)realloc(str, sizeof(char) * (i + 2));
      str[i++] = pow_count + 48;
      str[i++] = '0';
    } else {
      do {
        str = (char *)realloc(str, sizeof(char) * (i + 1));
        str[i++] = pow_count % 10 + 48;
        pow_count /= 10;
      } while (pow_count > 0);
    }
    if (specifier == 'g' || specifier == 'G') {
      specifier = (specifier == 'g') ? 'e' : 'E';
    }
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i++] = (pow_sign == 1) ? '+' : '-';
    str[i++] = specifier;
    int temp_accuracy_num = f_i.accuracy_num;
    while (temp_accuracy_num > 0 && current_part > 0) {
      temp_accuracy_num--;
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = current_part % 10 + 48;
      current_part /= 10;
    }
    while (temp_accuracy_num > 0) {
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = '0';
      temp_accuracy_num--;
    }
  } else {
    if (float_part > 0.5) {
      integer_part++;
      if (integer_part >= 10) {
        integer_part /= 10;
        pow_count++;
      }
    }
    int pow_sign = 1;
    if (pow_count < 0) {
      pow_sign = -1;
      pow_count = -pow_count;
    }
    if (pow_count < 10) {
      str = (char *)realloc(str, sizeof(char) * (i + 2));
      str[i++] = pow_count + 48;
      str[i++] = '0';
    } else {
      do {
        str = (char *)realloc(str, sizeof(char) * (i + 1));
        str[i++] = pow_count % 10 + 48;
        pow_count /= 10;
      } while (pow_count > 0);
    }
    if (specifier == 'g' || specifier == 'G') {
      specifier = (specifier == 'g') ? 'e' : 'E';
    }
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i++] = (pow_sign == 1) ? '+' : '-';
    str[i++] = specifier;
  }

  if (!(f_i.accuracy_num == 0 && f_i.flag_hashtag == 0)) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '.';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i++] = integer_part + 48;  // '48' = 0
  if (sign < 0) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '-';
  } else if (f_i.flag_plus == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '+';
  } else if (f_i.flag_space == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = ' ';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *e_specifier(char specifier, struct flags f_i, double argument) {
  char *str = NULL;
  str = itoa_exp(argument, f_i, specifier);
  return str;
}

char *l_itoa_exp(long double num, struct flags f_i, char specifier) {
  int i = 0;
  int pow_count = 0;
  char *str = (char *)malloc(sizeof(char));
  int sign = 1;
  int is_zero = 0;
  if (num == 0.0) {
    is_zero = 1;
  }
  if (num < 0) {
    sign = -1;
    num = -num;
  }
  //  -0.0012003 = -1.200300e-03
  // 120.0025 = 1.200025e+02
  if (num < 1 && is_zero == 0) {
    do {
      num *= 10;
      pow_count--;
    } while (num < 1);
  } else if (num > 10) {
    do {
      num /= 10;
      pow_count++;
    } while (num > 10);
  }
  long integer_part = (long)num;
  long double float_part = num - (long double)integer_part;
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 6;  // 0.12345
  }
  if (specifier == 'g' || specifier == 'G') {
    if (integer_part != 0) {
      f_i.accuracy_num--;
    }
  }
  if (f_i.accuracy_num != 0) {
    for (int j = 0; j < f_i.accuracy_num; j++) {  //   1.00001 false result
      float_part *= 10;
    }
    long current_part =
        (long)(float_part + 0.5);  // for successful round    check 1.9999996
    long powed = pow_m(10, f_i.accuracy_num);
    if (current_part >= powed) {
      current_part = current_part - powed;
      integer_part++;
      // printf("my %c %ld\n", specifier, integer_part);
      if (integer_part >= 10) {
        integer_part /= 10;
        pow_count++;
      }
    }

    int pow_sign = 1;
    if (pow_count < 0) {
      pow_sign = -1;
      pow_count = -pow_count;
    }
    if (pow_count < 10) {
      str = (char *)realloc(str, sizeof(char) * (i + 2));
      str[i++] = pow_count + 48;
      str[i++] = '0';
    } else {
      do {
        str = (char *)realloc(str, sizeof(char) * (i + 1));
        str[i++] = pow_count % 10 + 48;
        pow_count /= 10;
      } while (pow_count > 0);
    }
    if (specifier == 'g' || specifier == 'G') {
      specifier = (specifier == 'g') ? 'e' : 'E';
    }
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i++] = (pow_sign == 1) ? '+' : '-';
    str[i++] = specifier;
    int temp_accuracy_num = f_i.accuracy_num;
    while (temp_accuracy_num > 0 && current_part > 0) {
      temp_accuracy_num--;
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = current_part % 10 + 48;
      current_part /= 10;
    }
    while (temp_accuracy_num > 0) {
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = '0';
      temp_accuracy_num--;
    }
  } else {
    if (float_part > 0.5) {
      integer_part++;
      if (integer_part >= 10) {
        integer_part /= 10;
        pow_count++;
      }
    }
    int pow_sign = 1;
    if (pow_count < 0) {
      pow_sign = -1;
      pow_count = -pow_count;
    }
    if (pow_count < 10) {
      str = (char *)realloc(str, sizeof(char) * (i + 2));
      str[i++] = pow_count + 48;
      str[i++] = '0';
    } else {
      do {
        str = (char *)realloc(str, sizeof(char) * (i + 1));
        str[i++] = pow_count % 10 + 48;
        pow_count /= 10;
      } while (pow_count > 0);
    }
    if (specifier == 'g' || specifier == 'G') {
      specifier = (specifier == 'g') ? 'e' : 'E';
    }
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i++] = (pow_sign == 1) ? '+' : '-';
    str[i++] = specifier;
  }

  if (!(f_i.accuracy_num == 0 && f_i.flag_hashtag == 0)) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '.';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i++] = integer_part + 48;  // '48' = 0
  if (sign < 0) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '-';
  } else if (f_i.flag_plus == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '+';
  } else if (f_i.flag_space == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = ' ';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *le_specifier(char specifier, struct flags f_i, long double argument) {
  char *str = NULL;
  str = l_itoa_exp(argument, f_i, specifier);
  return str;
}

char *itoa_f(double num, struct flags f_i) {
  int i = 0;
  char *str = (char *)malloc(sizeof(char));
  int sign = 1;
  if (num < 0) {
    sign = -1;
    num = -num;
  }
  long integer_part = (long)num;
  double float_part = num - (double)integer_part;
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 6;
  }
  if (f_i.accuracy_num != 0) {
    for (int j = 0; j < f_i.accuracy_num; j++) {
      float_part *= 10;
    }  // float_part = float_part * pow(10, f_i.accuracy_num);
    long current_part = (long)(float_part + 0.5);  // for successful round
    long powed = pow_m(10, f_i.accuracy_num);
    if (current_part >= powed) {
      current_part = current_part - powed;
      integer_part++;
    }
    int temp_accuracy_num = f_i.accuracy_num;
    while (temp_accuracy_num > 0 && current_part > 0) {
      temp_accuracy_num--;
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = current_part % 10 + 48;
      current_part /= 10;
    }
    while (temp_accuracy_num > 0) {
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = '0';
      temp_accuracy_num--;
    }
  } else {
    if (float_part > 0.5) {
      integer_part++;
    }
  }
  if (!(f_i.accuracy_num == 0 && f_i.flag_hashtag == 0)) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '.';
  }

  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = integer_part % 10 + 48;
    integer_part /= 10;
  } while (integer_part > 0);

  if (sign < 0) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '-';
  } else if (f_i.flag_plus == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '+';
  } else if (f_i.flag_space == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = ' ';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *f_specifier(struct flags f_i, double argument) {
  char *str = NULL;
  str = itoa_f(argument, f_i);
  return str;
}

char *l_itoa_f(long double num, struct flags f_i) {
  int i = 0;
  char *str = (char *)malloc(sizeof(char));
  int sign = 1;
  if (num < 0) {
    sign = -1;
    num = -num;
  }
  long integer_part = (long)num;
  long double float_part = num - (long double)integer_part;
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 6;
  }
  if (f_i.accuracy_num != 0) {
    for (int j = 0; j < f_i.accuracy_num; j++) {
      float_part *= 10;
    }  // float_part = float_part * pow(10, f_i.accuracy_num);
    long current_part = (long)(float_part + 0.5);  // for successful round
    long powed = pow_m(10, f_i.accuracy_num);
    if (current_part >= powed) {
      current_part = current_part - powed;
      integer_part++;
    }
    int temp_accuracy_num = f_i.accuracy_num;
    while (temp_accuracy_num > 0 && current_part > 0) {
      temp_accuracy_num--;
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = current_part % 10 + 48;
      current_part /= 10;
    }
    while (temp_accuracy_num > 0) {
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = '0';
      temp_accuracy_num--;
    }
  } else {
    if (float_part > 0.5) {
      integer_part++;
    }
  }
  if (!(f_i.accuracy_num == 0 && f_i.flag_hashtag == 0)) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '.';
  }

  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = integer_part % 10 + 48;
    integer_part /= 10;
  } while (integer_part > 0);

  if (sign < 0) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '-';
  } else if (f_i.flag_plus == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '+';
  } else if (f_i.flag_space == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = ' ';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *lf_specifier(struct flags f_i, long double argument) {
  char *str = NULL;
  str = l_itoa_f(argument, f_i);
  return str;
}

int g_decide(double num,
             struct flags f_i) {  // result = 1 is 'e', result = 0 is 'f'
  int result = 0;
  int pow_count = 0;
  int is_zero = 0;
  if (num == 0.0) {
    is_zero = 1;
  }
  if (num < 0) {
    num = -num;
  }
  if (num < 1 && is_zero == 0) {
    do {
      num *= 10;
      pow_count--;
    } while (num < 1);
  } else if (num > 10) {
    do {
      num /= 10;
      pow_count++;
    } while (num > 10);
  }
  if (pow_count < -4 || pow_count >= f_i.accuracy_num) {
    result = 1;
  }
  return result;
}

char *g_specifier(char specifier, struct flags f_i, double argument) {
  char *str;

  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 6;
  }
  if (f_i.accuracy_num == 0) {
    f_i.accuracy_num = 1;
  }
  if (g_decide(argument, f_i) == 1) {
    str = e_specifier(specifier, f_i, argument);
    specifier = (specifier == 'g') ? 'e' : 'E';
    if (f_i.flag_hashtag == 0) {
      int j = 0;
      char *str_exp = (char *)malloc(sizeof(char));
      int i = s21_strlen(str) - 1;
      while (str[i] != specifier) {
        str_exp = (char *)realloc(str_exp, sizeof(char) * (j + 1));
        str_exp[j++] = str[i];
        i--;
      }
      str_exp = (char *)realloc(str_exp, sizeof(char) * (j + 2));
      str_exp[j++] = str[i];
      //
      str[i] = '\0';
      str_exp[j] = '\0';
      reverse_str(str_exp);
      i--;
      if (str[i] == '0') {
        while (str[i] == '0') {
          i--;
        }
        if (str[i] == '.') {
          str[i] = '\0';
        } else {
          str[i + 1] = '\0';
        }
      }
      str = (char *)realloc(
          str, sizeof(char) * (s21_strlen(str) + s21_strlen(str_exp) + 1));
      s21_strcat(str, str_exp);
      free(str_exp);
    }
  } else {
    str = f_specifier(f_i, argument);
    if (s21_strlen(str) > (long unsigned)f_i.accuracy_num) {
      int significant_num_count = 0;
      int i = 0;
      while ((long unsigned)i < s21_strlen(str) - 1 &&
             (str[i] < '1' || str[i] > '9')) {
        i++;
      }
      while ((long unsigned)i < s21_strlen(str)) {
        if (str[i] >= '0' && str[i] <= '9') {
          significant_num_count++;
        }
        if (significant_num_count > f_i.accuracy_num) {
          str[i] = '\0';
        }
        i++;
      }
    }
    if (f_i.flag_hashtag == 0) {
      int i = s21_strlen(str) - 1;
      while (str[i] == '0') {
        i--;
      }
      if (str[i] == '.') {
        str[i] = '\0';
      } else {
        str[i + 1] = '\0';
      }
    }
  }
  return str;
}

int lg_decide(long double num,
              struct flags f_i) {  // result = 1 is 'e', result = 0 is 'f'
  int result = 0;
  int pow_count = 0;
  int is_zero = 0;
  if (num == 0.0) {
    is_zero = 1;
  }
  if (num < 0) {
    num = -num;
  }
  if (num < 1 && is_zero == 0) {
    do {
      num *= 10;
      pow_count--;
    } while (num < 1);
  } else if (num > 10) {
    do {
      num /= 10;
      pow_count++;
    } while (num > 10);
  }
  if (pow_count < -4 || pow_count >= f_i.accuracy_num) {
    result = 1;
  }
  return result;
}

char *lg_specifier(char specifier, struct flags f_i, long double argument) {
  char *str;

  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 6;
  }
  if (f_i.accuracy_num == 0) {
    f_i.accuracy_num = 1;
  }
  if (lg_decide(argument, f_i) == 1) {
    str = le_specifier(specifier, f_i, argument);
    specifier = (specifier == 'g') ? 'e' : 'E';
    if (f_i.flag_hashtag == 0) {
      int j = 0;
      char *str_exp = (char *)malloc(sizeof(char));
      int i = s21_strlen(str) - 1;
      while (str[i] != specifier) {
        str_exp = (char *)realloc(str_exp, sizeof(char) * (j + 1));
        str_exp[j++] = str[i];
        i--;
      }
      str_exp = (char *)realloc(str_exp, sizeof(char) * (j + 2));
      str_exp[j++] = str[i];
      //
      str[i] = '\0';
      str_exp[j] = '\0';
      reverse_str(str_exp);
      i--;
      if (str[i] == '0') {
        while (str[i] == '0') {
          i--;
        }
        if (str[i] == '.') {
          str[i] = '\0';
        } else {
          str[i + 1] = '\0';
        }
      }
      str = (char *)realloc(
          str, sizeof(char) * (s21_strlen(str) + s21_strlen(str_exp) + 1));
      s21_strcat(str, str_exp);
      free(str_exp);
    }
  } else {
    str = lf_specifier(f_i, argument);
    if (s21_strlen(str) > (long unsigned)f_i.accuracy_num) {
      int significant_num_count = 0;
      int i = 0;
      while ((long unsigned)i < s21_strlen(str) - 1 &&
             (str[i] < '1' || str[i] > '9')) {
        i++;
      }
      while ((long unsigned)i < s21_strlen(str)) {
        if (str[i] >= '0' && str[i] <= '9') {
          significant_num_count++;
        }
        if (significant_num_count > f_i.accuracy_num) {
          str[i] = '\0';
        }
        i++;
      }
    }
    if (f_i.flag_hashtag == 0) {
      int i = s21_strlen(str) - 1;
      while (str[i] == '0') {
        i--;
      }
      if (str[i] == '.') {
        str[i] = '\0';
      } else {
        str[i + 1] = '\0';
      }
    }
  }
  return str;
}

char *itoa_o(unsigned int num, struct flags f_i) {
  char *str = (char *)malloc(sizeof(char));
  int i = 0;
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = num % 8 + 48;
    num /= 8;
  } while (num > 0);
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }

  if (f_i.flag_hashtag == 1 && str[i - 1] != '0') {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *o_specifier(struct flags f_i, unsigned int argument) {
  char *str = NULL;
  str = itoa_o(argument, f_i);
  return str;
}

char *h_itoa_o(unsigned short num, struct flags f_i) {
  char *str = (char *)malloc(sizeof(char));
  int i = 0;
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = num % 8 + 48;
    num /= 8;
  } while (num > 0);
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  if (f_i.flag_hashtag == 1 && str[i - 1] != '0') {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *ho_specifier(struct flags f_i, unsigned short argument) {
  char *str = NULL;
  str = h_itoa_o(argument, f_i);
  return str;
}

char *l_itoa_o(unsigned long num, struct flags f_i) {
  char *str = (char *)malloc(sizeof(char));
  int i = 0;
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = num % 8 + 48;
    num /= 8;
  } while (num > 0);
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  if (f_i.flag_hashtag == 1 && str[i - 1] != '0') {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *lo_specifier(struct flags f_i, unsigned long argument) {
  char *str = NULL;
  str = l_itoa_o(argument, f_i);
  return str;
}

char *itoa_u(unsigned int num, struct flags f_i) {
  char *str = (char *)malloc(sizeof(char));
  int i = 0;
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = num % 10 + 48;
    num /= 10;
  } while (num > 0);
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *u_specifier(struct flags f_i, unsigned int argument) {
  char *str = NULL;
  str = itoa_u(argument, f_i);
  return str;
}

char *h_itoa_u(unsigned short num, struct flags f_i) {
  char *str = (char *)malloc(sizeof(char));
  int i = 0;
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = num % 10 + 48;
    num /= 10;
  } while (num > 0);
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *hu_specifier(struct flags f_i, unsigned short argument) {
  char *str = NULL;
  str = h_itoa_u(argument, f_i);
  return str;
}

char *l_itoa_u(unsigned long num, struct flags f_i) {
  char *str = (char *)malloc(sizeof(char));
  int i = 0;
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = num % 10 + 48;
    num /= 10;
  } while (num > 0);
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *lu_specifier(struct flags f_i, unsigned long argument) {
  char *str = NULL;
  str = l_itoa_u(argument, f_i);
  return str;
}

char *itoa_x(unsigned int num, struct flags f_i, char specifier) {
  char *str = (char *)malloc(sizeof(char));
  int i = 0;
  int is_zero = (num == 0) ? 1 : 0;
  char *x_str = "0123456789ABCDEF";
  if (specifier == 'x' || specifier == 'p') {
    x_str = "0123456789abcdef";
  }
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = x_str[num % 16];
    num /= 16;
  } while (num > 0);
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  if (f_i.flag_hashtag == 1 && is_zero == 0 && specifier != 'p') {
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i++] = specifier;
    str[i++] = '0';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *x_specifier(char specifier, struct flags f_i, unsigned int argument) {
  char *str = NULL;
  str = itoa_x(argument, f_i, specifier);
  return str;
}

char *h_itoa_x(unsigned short num, struct flags f_i, char specifier) {
  char *str = (char *)malloc(sizeof(char));
  int i = 0;
  int is_zero = (num == 0) ? 1 : 0;
  char *x_str = "0123456789ABCDEF";
  if (specifier == 'x' || specifier == 'p') {
    x_str = "0123456789abcdef";
  }
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = x_str[num % 16];
    num /= 16;
  } while (num > 0);
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  if (f_i.flag_hashtag == 1 && is_zero == 0 && specifier != 'p') {
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i++] = specifier;
    str[i++] = '0';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *hx_specifier(char specifier, struct flags f_i, unsigned short argument) {
  char *str = NULL;
  str = h_itoa_x(argument, f_i, specifier);
  return str;
}

char *l_itoa_x(unsigned long num, struct flags f_i, char specifier) {
  char *str = (char *)malloc(sizeof(char));
  int i = 0;
  int is_zero = (num == 0) ? 1 : 0;
  char *x_str = "0123456789ABCDEF";
  if (specifier == 'x' || specifier == 'p') {
    x_str = "0123456789abcdef";
  }
  if (f_i.accuracy_num == -1) {
    f_i.accuracy_num = 1;
  }
  do {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = x_str[num % 16];
    num /= 16;
  } while (num > 0);
  while (i < f_i.accuracy_num) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '0';
  }
  if (f_i.flag_hashtag == 1 && is_zero == 0 && specifier != 'p') {
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i++] = specifier;
    str[i++] = '0';
  } else if (specifier == 'p') {
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i++] = 'x';
    str[i++] = '0';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  reverse_str(str);
  return str;
}

char *lx_specifier(char specifier, struct flags f_i, unsigned long argument) {
  char *str = NULL;
  str = l_itoa_x(argument, f_i, specifier);
  return str;
}

char *s_specifier(struct flags f_i, char *argument) {
  char *str = (char *)malloc(sizeof(char));
  int i = 0;
  while (argument[i] != '\0' &&
         (i < f_i.accuracy_num || f_i.accuracy_num == -1)) {
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i] = argument[i];
    i++;
  }
  str[i] = '\0';
  return str;
}

char *specifier_decide(char specifier, struct flags f_i, va_list args) {
  char *str;
  switch (specifier) {
    case 'c':
      str = (char *)malloc(sizeof(char) * 2);
      str[0] = va_arg(args, int);
      str[1] = '\0';
      break;
    case 'i':  // so i dont write same code twice
    case 'd':
      if (f_i.len_h == 1) {
        short argument = (short)va_arg(args, int);
        str = hd_specifier(f_i, argument);  // short
      } else if (f_i.len_l == 1) {
        str = ld_specifier(f_i, va_arg(args, long int));  // long
      } else {
        str = d_specifier(f_i, va_arg(args, int));  // default TYPE is int
      }
      break;
    case 'E':
    case 'e':
      if (f_i.len_L == 1) {
        str = le_specifier(specifier, f_i,
                           va_arg(args, long double));  // long double
      } else {
        str = e_specifier(specifier, f_i, va_arg(args, double));  // double
      }
      break;
    case 'f':
      if (f_i.len_L == 1) {
        str = lf_specifier(f_i, va_arg(args, long double));  // long double
      } else {
        str = f_specifier(f_i, va_arg(args, double));  // double
      }
      break;
    case 'g':
    case 'G':
      if (f_i.len_L == 1) {
        str = lg_specifier(specifier, f_i,
                           va_arg(args, long double));  // long double
      } else {
        str = g_specifier(specifier, f_i, va_arg(args, double));  // double
      }
      break;
    case 'o':
      if (f_i.len_h == 1) {
        unsigned short argument = (short)va_arg(args, unsigned int);
        str = ho_specifier(f_i, argument);  // u short
      } else if (f_i.len_l == 1) {
        str = lo_specifier(f_i, va_arg(args, unsigned long));  // u long
      } else {
        str = o_specifier(f_i, va_arg(args, unsigned int));  // u int
      }
      break;
    case 's':
      // if (f_i.len_l == 1) {
      // } else {
      // }
      str = s_specifier(f_i, va_arg(args, char *));  // need to do w_char
      break;
    case 'u':
      if (f_i.len_h == 1) {
        unsigned short argument = (short)va_arg(args, unsigned int);
        str = hu_specifier(f_i, argument);  // u short
      } else if (f_i.len_l == 1) {
        str = lu_specifier(f_i, va_arg(args, unsigned long));  // u long
      } else {
        str = u_specifier(f_i, va_arg(args, unsigned int));  // u int
      }
      break;
    case 'p':
      str = lx_specifier('p', f_i, va_arg(args, unsigned long));
      break;
    case 'x':
    case 'X':
      if (f_i.len_h == 1) {
        unsigned short argument = (short)va_arg(args, unsigned int);
        str = hx_specifier(specifier, f_i, argument);  // u short
      } else if (f_i.len_l == 1) {
        str = lx_specifier(specifier, f_i,
                           va_arg(args, unsigned long));  // u long
      } else {
        str = x_specifier(specifier, f_i, va_arg(args, unsigned int));  // u int
      }
      break;
    case '%':
      str = (char *)malloc(sizeof(char) * 2);
      str[0] = '%';
      str[1] = '\0';
      break;
  }
  return str;
}

int s21_sprintf(char *str, const char *format, ...) {  // etc arguments
  int i = 0;  // "format" string char counter
  int j = 0;  // "str" string char counter
  int number_of_symbols = 0;
  str[j] = '\0';
  char spec_str[17] = "cdieEfgGosuxXpn%";  // string of specifiers
  va_list args;
  va_start(args, format);
  while (format[i] != '\0') {
    if (format[i] == '%') {
      int flag_len = 1;
      char *flag_str = (char *)malloc(sizeof(char));
      i++;
      while (s21_strchr(spec_str, format[i]) == NULL) {
        flag_str = (char *)realloc(flag_str, sizeof(char) * (flag_len + 1));
        flag_str[flag_len - 1] = format[i];
        flag_len++;
        i++;
      }
      flag_str[flag_len - 1] = '\0';
      struct flags f_i = flag_parser(
          flag_str,
          flag_len);  // f_i = flags_info;  flag_str is freed in flag_parser
      if (f_i.width_star == 1) {
        f_i.width_num = va_arg(args, int);
      }
      if (f_i.accuracy_star == 1) {
        f_i.accuracy_num = va_arg(args, int);
      }
      if (format[i] == 'n') {
        *va_arg(args, int *) = number_of_symbols;
      } else {
        char *str_to_cat = specifier_decide(format[i], f_i, args);
        int s21_strlen_str_to_cat = s21_strlen(str_to_cat);
        if (f_i.width_num != 0 && (f_i.width_num - s21_strlen_str_to_cat) > 0) {
          int fill = 0;
          f_i.width_num = f_i.width_num - s21_strlen_str_to_cat;
          if (f_i.flag_minus == 1) {
            char *str_to_expand =
                (char *)malloc(sizeof(char) * (f_i.width_num + 1));
            for (; fill < f_i.width_num; str_to_expand[fill++] = ' ')
              ;
            str_to_expand[fill] = '\0';
            str_to_cat = (char *)realloc(
                str_to_cat, sizeof(char) * (s21_strlen(str_to_cat) +
                                            s21_strlen(str_to_expand) + 1));
            s21_strcat(str_to_cat, str_to_expand);
            free(str_to_expand);  // here
          } else if (f_i.flag_null == 1) {
            char *str_to_expand =
                (char *)malloc(sizeof(char) * (f_i.width_num + 1));
            for (; fill < f_i.width_num; str_to_expand[fill++] = '0')
              ;
            str_to_expand[fill] = '\0';
            str_to_expand = (char *)realloc(
                str_to_expand, sizeof(char) * (s21_strlen(str_to_expand) +
                                               s21_strlen(str_to_cat) + 1));
            s21_strcat(str_to_expand, str_to_cat);
            char *ptr_to_free = str_to_cat;
            str_to_cat = str_to_expand;
            free(ptr_to_free);
          } else {
            char *str_to_expand =
                (char *)malloc(sizeof(char) * (f_i.width_num + 1));
            for (; fill < f_i.width_num; str_to_expand[fill++] = ' ')
              ;
            str_to_expand[fill] = '\0';  // here
            str_to_expand = (char *)realloc(
                str_to_expand, sizeof(char) * (s21_strlen(str_to_expand) +
                                               s21_strlen(str_to_cat) + 1));
            s21_strcat(str_to_expand, str_to_cat);
            char *ptr_to_free = str_to_cat;
            str_to_cat = str_to_expand;
            free(ptr_to_free);
          }
        }
        s21_strcat(str, str_to_cat);
        number_of_symbols += s21_strlen(str_to_cat);
        j += s21_strlen(str_to_cat);
        free(str_to_cat);
      }
      i++;
    } else {
      number_of_symbols++;
      str[j] = format[i];
      i++;
      j++;
      str[j] = '\0';
    }
  }
  va_end(args);

  return s21_strlen(str);
}
