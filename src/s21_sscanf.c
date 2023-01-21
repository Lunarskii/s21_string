#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  // %[*][ширина][длина]спецификатор
  int conversions = 0;
  int convSuccess = 1;
  int success = 0;
  int specifierC = 0;

  if (checkFormatErrors(format, &specifierC)) success = 1;

  if (checkStringOnEmptiness(str, specifierC)) {
    const char *string = str;
    const char *fmt = format;
    va_list list;
    va_start(list, format);
    long int stringSize = s21_strlen(str);
    int shift = 0;

    while (*fmt != '\0') {
      if (isTab(*fmt)) shift = 1;
      if (*fmt == '%') {
        fmt++;
        options data = {-1, 0, ' ', ' ', 0, 0, 0, ' ', 0, 0, 0, 0, 1};
        parseFormat(&fmt, &data);
        success = 1;
        if (data.error) break;

        if (data.star && convSuccess) {
          convSuccess = asterisk(&string, &data);
          continue;
        }
        if (convSuccess) {
          parseString(&string, data, list, stringSize, shift, &conversions,
                      &convSuccess);
        }
        shift = 0;
      }
      fmt++;
    }
    va_end(list);
  } else {
    success = 0;
  }

  return success ? conversions : -1;
}

void clearArray(char *string, int size) {
  for (int i = 0; i < size; i++) {
    string[i] = 0;
  }
}
int checkFormatErrors(const char *format, int *specifierC) {
  char buffer[16] = "cdieEfgGosuxXpn%";
  int error = 1;

  for (; *format; format++) {
    if (*format == '%') {
      format++;
      if (*format == 'c') *specifierC = 1;
      for (int i = 0; i < 16; i++) {
        if (buffer[i] == *format) {
          error = 0;
        }
      }
      if (error) break;
    }
  }
  if (error) *specifierC = 0;

  return error;
}
int asterisk(const char **string, options *data) {
  int convSuccess = 0;
  if (data->specifier == 'i') {
    data->specifier = 'd';
    if (**string == '0' && data->width) {
      (*string)++;
      if (data->width != -1) (data->width)--;
      if ((**string == 'x' || **string == 'X') && data->width) {
        (*string)++;
        if (data->width != -1) (data->width)--;
      }
      convSuccess = 1;
    }
  }
  int dot = 0;
  int exp = 0;
  switch (data->specifier) {
    case 'c':
      while (data->width && **string != '\0') {
        (*string)++;
        convSuccess = 1;
        if (data->width != -1) {
          (data->width)--;
        } else {
          break;
        }
      }
      break;
    case 's':
      while (isTab(**string) && **string != '\0') (*string)++;
      while (!isTab(**string) && data->width) {
        (*string)++;
        if (data->width != -1) (data->width)--;
        convSuccess = 1;
      }
      break;
    case 'u':
    case 'd':
      while (isTab(**string) && **string != '\0') (*string)++;
      while (!isTab(**string) && isDec(**string) && data->width) {
        (*string)++;
        if (data->width != -1) (data->width)--;
        convSuccess = 1;
      }
      break;
    case 'o':
      while (isTab(**string) && **string != '\0') (*string)++;
      while (!isTab(**string) && isOct(**string) && data->width) {
        (*string)++;
        if (data->width != -1) (data->width)--;
        convSuccess = 1;
      }
      break;
    case 'x':
      while (isTab(**string) && **string != '\0') (*string)++;
      if (**string == '0' && data->width) {
        (*string)++;
        if (data->width != -1) (data->width)--;
        if ((**string == 'x' || **string == 'X') && data->width) {
          (*string)++;
          if (data->width != -1) (data->width)--;
        }
        convSuccess = 1;
      }
      while (!isTab(**string) && isHex(**string) && data->width) {
        (*string)++;
        if (data->width != -1) (data->width)--;
        convSuccess = 1;
      }
      break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      while (isTab(**string) && **string != '\0') (*string)++;
      while (!isTab(**string) &&
             (**string == '.' || isExp(**string) || isDec(**string)) &&
             data->width) {
        if ((dot && **string == '.') || (exp && isExp(**string))) break;
        if (isExp(**string)) exp = 1;
        if (**string == '.') dot = 1;
        (*string)++;
        if (data->width != -1) (data->width)--;
        convSuccess = 1;
      }
      break;
  }

  return convSuccess;
}
int checkStringOnEmptiness(const char *string, int formatCheck) {
  int result = 0;
  const char *ptr = string;

  for (; *ptr; ptr++) {
    if (!formatCheck) {
      if (!isTab(*ptr)) {
        result = 1;
        break;
      }
    } else {
      if (*ptr != '\0') {
        result = 1;
        break;
      }
    }
  }

  return result;
}

int isDec(char c) { return c >= '0' && c <= '9'; }
int isChr(char c) { return c >= 0; }
int isHex(char c) {
  return isDec(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}
int isOct(char c) { return c >= '0' && c <= '7'; }
int isTab(char c) { return c == ' ' || c == '\n' || c == '\t' || c == '\0'; }
int isSign(char c) { return c == '+' || c == '-'; }
int isExp(char c) { return c == 'e' || c == 'E'; }
int isScience(char c) { return c == '.' || isExp(c) || isSign(c) || isDec(c); }
int isNANorINF(const char *string, options data) {
  int result = 0;

  if (data.width == -1 || data.width >= 3) {
    if (*string == 'n' || *string == 'N') {
      if (*(string + 1) == 'a' || *(string + 1) == 'A') {
        if (*(string + 2) == 'n' || *(string + 2) == 'N') {
          result = 1;
        }
      }
    } else if (*string == 'i' || *string == 'I') {
      if (*(string + 1) == 'n' || *(string + 1) == 'N') {
        if (*(string + 2) == 'f' || *(string + 2) == 'F') {
          result = 2;
        }
      }
    }
  }

  return result;
}

long int s21_ohtoi(char *string, int radix) {
  int valueSize = s21_strlen(string);
  int degree = valueSize - 1;
  long int result = 0;
  int temp = 0;
  int sign = 0;

  if (isSign(*string)) {
    if (*string == '-') sign = 1;
    string++;
    degree--;
  }
  for (; *string != '\0'; degree--, string++) {
    if (*string >= 'A' && *string <= 'F') {
      temp = *string - 55;
    } else if (*string >= 'a' && *string <= 'f') {
      temp = *string - 87;
    } else {
      temp = *string - 48;
    }
    result += temp * pow(radix, degree);
  }
  if (sign) result *= -1;

  return result;
}
int s21_atoi(const char *string) {
  const char *ptr = string;
  int result = 0;
  int sign = 0;

  if (*ptr == '+' || *ptr == '-') {
    if (*ptr == '-') sign = 1;
    ptr++;
  }
  for (; *ptr && *ptr >= '0' && *ptr <= '9'; ptr++) {
    result = result * 10 + (*ptr - 48);
  }
  if (sign) result *= -1;

  return result;
}
unsigned int s21_atoui(const char *string) {
  const char *ptr = string;
  unsigned int result = 0;
  int sign = 0;

  if (*ptr == '+' || *ptr == '-') {
    if (*ptr == '-') sign = 1;
    ptr++;
  }
  for (; *ptr && *ptr >= '0' && *ptr <= '9'; ptr++) {
    result = result * 10 + (*ptr - 48);
  }
  if (sign) result *= -1;

  return result;
}
long int s21_atol(char *string) {
  const char *ptr = string;
  long int result = 0;
  int sign = 0;

  if (*ptr == '+' || *ptr == '-') {
    if (*ptr == '-') sign = 1;
    ptr++;
  }
  for (; *ptr && *ptr >= '0' && *ptr <= '9'; ptr++) {
    result = result * 10 + (*ptr - 48);
  }
  if (sign) result *= -1;

  return result;
}
unsigned long int s21_atoul(const char *string) {
  const char *ptr = string;
  unsigned long int result = 0;
  int sign = 0;

  if (*ptr == '+' || *ptr == '-') {
    if (*ptr == '-') sign = 1;
    ptr++;
  }
  for (; *ptr && *ptr >= '0' && *ptr <= '9'; ptr++) {
    result = result * 10 + (*ptr - 48);
  }
  if (sign) result *= -1;

  return result;
}
short int s21_atos(char *string) {
  const char *ptr = string;
  short int result = 0;
  int sign = 0;

  if (*ptr == '+' || *ptr == '-') {
    if (*ptr == '-') sign = 1;
    ptr++;
  }
  for (; *ptr && *ptr >= '0' && *ptr <= '9'; ptr++) {
    result = result * 10 + (*ptr - 48);
  }
  if (sign) result *= -1;

  return result;
}
unsigned short int s21_atous(char *string) {
  const char *ptr = string;
  unsigned short int result = 0;
  int sign = 0;

  if (*ptr == '+' || *ptr == '-') {
    if (*ptr == '-') sign = 1;
    ptr++;
  }
  for (; *ptr && *ptr >= '0' && *ptr <= '9'; ptr++) {
    result = result * 10 + (*ptr - 48);
  }
  if (sign) result *= -1;

  return result;
}
long double s21_atof(const char *string) {
  const char *ptr2 = string;
  const char *ptr = string;
  int decBeforeDot = 0;
  int dotEnabled = 0;
  int sign = 0;
  long double result = 0;

  if (isSign(*ptr2)) {
    if (*ptr2 == '-') sign = 1;
    ptr2++;
    ptr++;
  }
  for (; *ptr2 && (isDec(*ptr2) || *ptr2 == '.'); ptr2++) {
    if (*ptr2 == '.') {
      dotEnabled = 1;
      break;
    }
    decBeforeDot++;
  }
  for (int i = decBeforeDot - 1; i != -1; i--, ptr++) {
    result += pow(DEC, i) * (*ptr - 48);
  }
  if (dotEnabled) {
    ptr++;
    for (int i = 1; *ptr != '\0' && isDec(*ptr); i++, ptr++) {
      result += pow(DEC, -i) * (*ptr - 48);
    }
  }
  if (sign) result *= -1;

  return result;
}
long double s21_atoe(char *string, options data) {
  long double result = 0;
  int sign = 0;

  if (data.exp) {
    if (isSign(*string)) {
      if (*string == '-') sign = 1;
      string++;
    }
    char buffer[data.quantitySymbolsBeforeExp + 1];
    clearArray(buffer, data.quantitySymbolsBeforeExp + 1);
    s21_memcpy(buffer, string, data.quantitySymbolsBeforeExp);
    result = s21_atof(buffer);
    string += data.quantitySymbolsBeforeExp + 1;
    if (data.expInt) {
      result *= pow(DEC, s21_atoi(string));
    } else if (data.expSignInt) {
      string++;
      if (data.signBuffer == '+') {
        result *= pow(DEC, s21_atoi(string));
      } else {
        result *= pow(DEC, -s21_atoi(string));
      }
    }
    if (sign) result *= -1;
  } else {
    result = s21_atof(string);
  }

  return result;
}
unsigned long int s21_atop(const char *string) {
  unsigned long int result = 0;
  int degree = 0;
  int temp = 0;
  int sign = 0;

  if (isSign(*string)) {
    if (*string == '-') sign = 1;
    string++;
  }
  degree = s21_strlen(string) - 1;
  for (; *string != '\0' && degree >= 0; string++, degree--) {
    if (*string >= 'A' && *string <= 'F') {
      temp = *string - 55;
    } else if (*string >= 'a' && *string <= 'f') {
      temp = *string - 87;
    } else {
      temp = *string - 48;
    }
    result += pow(HEX, degree) * temp;
  }
  if (sign) result *= -1;

  return result;
}

void parseSpecifier(const char ***format, options *data) {
  char buffer[16] = "cdieEfgGosuxXpn%";

  for (int i = 0; i < 16; i++) {
    if (***format == buffer[i]) {
      data->specifier = ***format;
      data->error = 0;
      break;
    }
  }
}
void parseWidth(const char ***format, options *data) {
  long int result = 0;
  int i = 0;

  for (; isDec(***format) || ***format == '*'; (**format)++) {
    if (***format == '*') {
      data->star = 1;
    } else {
      result = result * 10 + (***format - 48);
      i++;
    }
  }
  if (i) data->width = result;
}
void parseLength(const char ***format, options *data) {
  if (***format == 'h' || ***format == 'l' || ***format == 'L') {
    data->length = ***format;
    (**format)++;
    if (data->length == 'l' && ***format == 'l') (**format)++;
  }
}
void parseFormat(const char **format, options *data) {
  parseWidth(&format, data);
  parseLength(&format, data);
  parseSpecifier(&format, data);
}
void parseString(const char **string, options data, va_list list,
                 long int stringSize, int shift, int *conversions,
                 int *convSuccess) {
  char resultString[1024] = {0};

  while (isTab(**string) && (data.specifier != 'c' || shift) &&
         **string != '\0') {
    (*string)++;
    if (!shift && data.specifier != 'n') stringSize--;
  }
  if ((**string && *convSuccess) || data.specifier == 'n') {
    if (data.specifier != '%' && data.specifier != 'n' &&
        data.specifier != 'c' && data.specifier != 's') {
      signExecution(&string, &resultString[0], &data);
    }
    const char *ptr = *string;
    int sizeNow = s21_strlen(*string);
    switch (data.specifier) {
      case 'c':
        *convSuccess = charExecution(&string, data, list);
        break;
      case 'd':
        *convSuccess = decExecution(&string, resultString, data, list);
        break;
      case 'i':
        if (*ptr == '0') {
          ptr++;
          if (*ptr == 'x' || *ptr == 'X') {
            *convSuccess = hexExecution(&string, resultString, data, list);
          } else {
            *convSuccess = octExecution(&string, resultString, data, list);
          }
        } else {
          *convSuccess = decExecution(&string, resultString, data, list);
        }
        break;
      case 'e':
      case 'E':
      case 'f':
      case 'g':
      case 'G':
        *convSuccess = scienceExecution(&string, resultString, data, list);
        break;
      case 'o':
        *convSuccess = octExecution(&string, resultString, data, list);
        break;
      case 's':
        *convSuccess = stringExecution(&string, resultString, data, list);
        break;
      case 'u':
        *convSuccess = decExecution(&string, resultString, data, list);
        break;
      case 'x':
      case 'X':
        *convSuccess = hexExecution(&string, resultString, data, list);
        break;
      case 'p':
        *convSuccess = ptrExecution(&string, resultString, data, list);
        break;
      case 'n':
        if (!shift && stringSize - sizeNow > 1) {
          sizeNow++;
        }
        nExecution(stringSize - sizeNow, data, list);
        *convSuccess = 1;
        break;
      case '%':
        if (**string == '%') (*string)++;
        *convSuccess = 1;
        break;
    }
  } else {
    *convSuccess = 0;
  }
  if (*convSuccess) {
    if (data.specifier != '%' && data.specifier != 'n') (*conversions)++;
  }
}
void parseScienceNotation(const char ****string, char **resultString,
                          options *data) {
  char *ptr = *resultString;
  char lastSymbol = ' ';

  if (isSign(*ptr)) ptr++;
  while (data->width && isScience(****string)) {
    if (((data->dot || data->exp) && ****string == '.') ||
        (data->exp && isExp(****string)) ||
        (data->sign && isSign(****string))) {
      break;
    }

    if (data->sign && isDec(****string)) {
      data->expSignInt = 1;
    } else if (isExp(lastSymbol) && isDec(****string)) {
      data->expInt = 1;
    }

    if (!(isExp(lastSymbol)) && isSign(****string)) {
      (***string)++;
      break;
    } else {
      *ptr = ****string;
      (***string)++;
      if (data->width != -1) data->width--;
    }
    lastSymbol = *ptr;
    if (lastSymbol == '.') {
      data->dot = 1;
    } else if (isExp(lastSymbol)) {
      data->exp = 1;
    } else if (isSign(lastSymbol)) {
      data->sign = 1;
      data->signBuffer = lastSymbol;
    }
    if (!data->exp) data->quantitySymbolsBeforeExp++;
    ptr++;
  }
}

void execution(const char ****string, char **resultString, options *data) {
  **resultString = ****string;
  (***string)++;
  (*resultString)++;
  if (data->width != -1) data->width--;
}
void signExecution(const char ***string, char *resultString, options *data) {
  const char *ptr = **string;

  if (isSign(*ptr)) {
    ptr++;
    if (data->specifier == 'e' || data->specifier == 'E' ||
        data->specifier == 'f' || data->specifier == 'g' ||
        data->specifier == 'G') {
      if (isDec(*ptr) || isExp(*ptr) || *ptr == '.') {
        *resultString = ***string;
        (**string)++;
      } else if (isNANorINF(ptr, *data)) {
        *resultString = ***string;
        (**string)++;
      }
    } else if (data->specifier == 'd' || data->specifier == 'u' ||
               data->specifier == 'o' || data->specifier == 'i') {
      if (isDec(*ptr)) {
        *resultString = ***string;
        (**string)++;
      }
    } else if (data->specifier == 'x' || data->specifier == 'X' ||
               data->specifier == 'p') {
      if (isHex(*ptr)) {
        *resultString = ***string;
        (**string)++;
      }
    }
    if (data->width != -1) (data->width)--;
  }
}
void nExecution(long int n, options data, va_list list) {
  if (data.length == 'h') {
    *va_arg(list, short int *) = (short int)n;
  } else if (data.length == 'l') {
    *va_arg(list, long int *) = (long int)n;
  } else {
    *va_arg(list, int *) = (int)n;
  }
}
int ptrExecution(const char ***string, char *resultString, options data,
                 va_list list) {
  char *ptr = resultString;
  void **dest = va_arg(list, void **);
  int convSuccess = 0;
  int sign = 0;
  int ptrFlag = 0;

  if (isSign(*ptr)) {
    ptr++;
    sign = 1;
  }
  if (***string == '0') {
    (**string)++;
    if (***string == 'x' || ***string == 'X') {
      (**string)++;
    }
    ptrFlag = 1;
  }
  while (data.width && isHex(***string)) {
    execution(&string, &ptr, &data);
  }
  if (s21_strlen(resultString + sign) != 0 || ptrFlag) {
    *dest = (void *)s21_atop(resultString);
    convSuccess = 1;
  }

  return convSuccess;
}
int charExecution(const char ***string, options data, va_list list) {
  int convSuccess = 0;

  if (isChr(***string)) {
    *va_arg(list, char *) = ***string;
    convSuccess = 1;
    if (data.width != -1) data.width--;
  }
  (**string)++;
  while (data.width > 0 && ***string != '\0') {
    data.width--;
    (**string)++;
  }

  return convSuccess;
}
int scienceExecution(const char ***string, char *resultString, options data,
                     va_list list) {
  int mode = isNANorINF(**string, data);
  char *ptr = resultString;
  int convSuccess = 0;
  int sign = 0;

  if (isSign(*ptr)) {
    ptr++;
    sign = 1;
  }
  if (mode == 0) {
    parseScienceNotation(&string, &resultString, &data);
    double result_atoe = s21_atoe(resultString, data);
    if (s21_strlen(resultString + sign) != 0 && result_atoe != 0) {
      assignmentScience(resultString, data, list);
      convSuccess = 1;
    }
  } else {
    double x;

    (**string) += 3;
    if (mode == 1) {
      x = -(0.0 / 0.0);
    } else if (mode == 2) {
      x = __builtin_huge_vall();
    }
    if (*resultString == '-') x *= -1;
    *resultString = '1';
    assignmentNANandINF(x, data, list);
    convSuccess = 1;
  }

  return convSuccess;
}
int stringExecution(const char ***string, char *resultString, options data,
                    va_list list) {
  char *ptr = resultString;
  int convSuccess = 0;

  while (data.width && isChr(***string) && !isTab(***string)) {
    execution(&string, &ptr, &data);
  }
  if (s21_strlen(resultString) != 0) {
    s21_strcpy(va_arg(list, char *), resultString);
    convSuccess = 1;
  }

  return convSuccess;
}
int octExecution(const char ***string, char *resultString, options data,
                 va_list list) {
  char *ptr = resultString;
  int convSuccess = 0;
  int sign = 0;
  int oct = 0;

  if (isSign(*ptr)) {
    ptr++;
    sign = 1;
  }
  if (***string == '0' && data.width) {
    (**string)++;
    oct = 1;
    if (data.width != -1) data.width--;
  }
  while (data.width && isOct(***string)) {
    execution(&string, &ptr, &data);
  }
  if (s21_strlen(resultString + sign) != 0 || oct) {
    assignmentOct(resultString, data, list);
    convSuccess = 1;
  }

  return convSuccess;
}
int hexExecution(const char ***string, char *resultString, options data,
                 va_list list) {
  char *ptr = resultString;
  int convSuccess = 0;
  int sign = 0;
  int hex = 0;

  if (isSign(*ptr)) {
    ptr++;
    sign = 1;
  }
  if (***string == '0' && data.width) {
    (**string)++;
    if (data.width != -1) data.width--;
    if ((***string == 'x' || ***string == 'X') && data.width) {
      (**string)++;
      if (data.width != -1) data.width--;
    }
    hex = 1;
  }
  while (data.width && isHex(***string)) {
    execution(&string, &ptr, &data);
  }
  if (s21_strlen(resultString + sign) != 0 || hex) {
    assignmentHex(resultString, data, list);
    convSuccess = 1;
  }

  return convSuccess;
}
int decExecution(const char ***string, char *resultString, options data,
                 va_list list) {
  char *ptr = resultString;
  int convSuccess = 0;
  int sign = 0;

  if (isSign(*ptr)) {
    ptr++;
    sign = 1;
  }
  while (data.width && isDec(***string)) {
    execution(&string, &ptr, &data);
  }
  if (s21_strlen(resultString + sign) != 0) {
    assignmentDec(resultString, data, list);
    convSuccess = 1;
  }

  return convSuccess;
}

void assignmentScience(char *string, options data, va_list list) {
  if (data.length == 'l') {
    *va_arg(list, double *) = (double)s21_atoe(string, data);
  } else if (data.length == 'L') {
    *va_arg(list, long double *) = (long double)s21_atoe(string, data);
  } else {
    *va_arg(list, float *) = (float)s21_atoe(string, data);
  }
}
void assignmentNANandINF(double x, options data, va_list list) {
  if (data.length == 'l') {
    *va_arg(list, double *) = (double)x;
  } else if (data.length == 'L') {
    *va_arg(list, long double *) = (long double)x;
  } else {
    *va_arg(list, float *) = (float)x;
  }
}
void assignmentOct(char *string, options data, va_list list) {
  if (data.specifier == 'i') {
    if (data.length == 'h') {
      *va_arg(list, short int *) = (short int)s21_ohtoi(string, OCT);
    } else if (data.length == 'l') {
      *va_arg(list, long int *) = (long int)s21_ohtoi(string, OCT);
    } else {
      *va_arg(list, int *) = (int)s21_ohtoi(string, OCT);
    }
  } else {
    if (data.length == 'h') {
      *va_arg(list, unsigned short int *) =
          (unsigned short int)s21_ohtoi(string, OCT);
    } else if (data.length == 'l') {
      *va_arg(list, unsigned long int *) =
          (unsigned long int)s21_ohtoi(string, OCT);
    } else {
      *va_arg(list, unsigned int *) = (unsigned int)s21_ohtoi(string, OCT);
    }
  }
}
void assignmentHex(char *string, options data, va_list list) {
  if (data.specifier == 'i') {
    if (data.length == 'h') {
      *va_arg(list, short int *) = (short int)s21_ohtoi(string, HEX);
    } else if (data.length == 'l') {
      *va_arg(list, long int *) = (long int)s21_ohtoi(string, HEX);
    } else {
      *va_arg(list, int *) = (int)s21_ohtoi(string, HEX);
    }
  } else {
    if (data.length == 'h') {
      *va_arg(list, unsigned short int *) =
          (unsigned short int)s21_ohtoi(string, HEX);
    } else if (data.length == 'l') {
      *va_arg(list, unsigned long int *) =
          (unsigned long int)s21_ohtoi(string, HEX);
    } else {
      *va_arg(list, unsigned int *) = (unsigned int)s21_ohtoi(string, HEX);
    }
  }
}
void assignmentDec(char *string, options data, va_list list) {
  if (data.specifier == 'd') {
    if (data.length == 'h') {
      *va_arg(list, short int *) = (short int)s21_atos(string);
    } else if (data.length == 'l') {
      *va_arg(list, long int *) = (long int)s21_atol(string);
    } else {
      *va_arg(list, int *) = (int)s21_atoi(string);
    }
  } else {
    if (data.length == 'h') {
      *va_arg(list, unsigned short int *) =
          (unsigned short int)s21_atous(string);
    } else if (data.length == 'l') {
      *va_arg(list, unsigned long int *) = (unsigned long int)s21_atoul(string);
    } else {
      *va_arg(list, unsigned int *) = (unsigned int)s21_atoui(string);
    }
  }
}
