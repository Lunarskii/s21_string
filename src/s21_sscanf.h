#ifndef _SRC_S21_SSCANF_H
#define _SRC_S21_SSCANF_H

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "s21_string.h"

#define HEX 16
#define OCT 8
#define DEC 10

typedef struct {
  int width;
  int star;
  char specifier;
  char length;
  int dot;
  int exp;
  int sign;
  char signBuffer;
  int expSignInt;
  int expInt;
  int quantitySymbolsBeforeExp;
  int conversions;
  int error;
} options;

int s21_sscanf(const char *str, const char *format, ...)
    __attribute__((format(scanf, 2, 3)));
void clearArray(char *string, int size);
int checkStringOnEmptiness(const char *string, int formatCheck);
int asterisk(const char **string, options *data);
int checkFormatErrors(const char *format, int *specifierC);

int isDec(char c);
int isChr(char c);
int isHex(char c);
int isOct(char c);
int isTab(char c);
int isSign(char c);
int isExp(char c);
int isScience(char c);
int isNANorINF(const char *string, options data);

long int s21_ohtoi(char *string, int radix);
short int s21_atos(char *string);
int s21_atoi(const char *string);
long int s21_atol(char *string);
unsigned short int s21_atous(char *string);
unsigned int s21_atoui(const char *string);
unsigned long int s21_atoul(const char *string);
long double s21_atof(const char *string);
long double s21_atoe(char *string, options data);
unsigned long int s21_atop(const char *string);

void parseSpecifier(const char ***format, options *data);
void parseWidth(const char ***format, options *data);
void parseLength(const char ***format, options *data);
void parseFormat(const char **format, options *data);
void parseString(const char **string, options data, va_list list,
                 long int stringSize, int shift, int *conversions,
                 int *convSuccess);
void parseScienceNotation(const char ****string, char **resultString,
                          options *data);

void execution(const char ****string, char **resultString, options *data);
void signExecution(const char ***string, char *resultString, options *data);
void nExecution(long int n, options data, va_list list);
int ptrExecution(const char ***string, char *resultString, options data,
                 va_list list);
int scienceExecution(const char ***string, char *resultString, options data,
                     va_list list);
int charExecution(const char ***string, options data, va_list list);
int stringExecution(const char ***string, char *resultString, options data,
                    va_list list);
int octExecution(const char ***string, char *resultString, options data,
                 va_list list);
int hexExecution(const char ***string, char *resultString, options data,
                 va_list list);
int decExecution(const char ***string, char *resultString, options data,
                 va_list list);

void assignmentScience(char *string, options data, va_list list);
void assignmentNANandINF(double x, options data, va_list list);
void assignmentOct(char *string, options data, va_list list);
void assignmentHex(char *string, options data, va_list list);
void assignmentDec(char *string, options data, va_list list);

#endif  // _SRC_S21_SSCANF_H
