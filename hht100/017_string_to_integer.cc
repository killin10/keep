//
// @file 017_atoi.cc
// @brief Convert a string to an integer.
// 
// @version 1.0 
// @date Sun Jun 16 22:49:36 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

bool StringToInteger(const char* str, int* integer) {
  assert(str != NULL);
  assert(integer != NULL);

  if ('\0' == str[0]) {
    // invalid
    return false;
  }

  const char kPositiveSign = '+';
  const char kNegativeSign = '-';

  bool positive = true;
  bool have_sign = false;
  char sign = str[0];
  if (kNegativeSign == sign) {
    positive = false;
    have_sign = true;
  } else if (kPositiveSign == sign) {
    positive = true;
    have_sign = true;
  } else if (sign >= '0' && sign <= '9') {
    positive = true;
  } else {
    // invalid
    return false;
  }

  const char* pos = str;
  if (have_sign) {
    ++pos;
  }

  int tmp_int = 0;
  while (*pos != '\0') {
    if (!(*pos >= '0' && *pos <= '9')) {
      return false;
    }
    tmp_int = tmp_int * 10 + (*pos - '0');
    ++pos;
  }

  if (!positive) {
    *integer = -tmp_int;
  } else {
    *integer = tmp_int;
  }

  return true;
}

void TestStringToInteger(const char* str) {
  int integer = 0;
  if(StringToInteger(str, &integer)) {
    std::cout << integer << std::endl;
  } else {
    std::cout << "Convert error!" << std::endl;
  }
}

int main(int argc, char* argv[]) {
  TestStringToInteger("+10");
  TestStringToInteger("-10");
  TestStringToInteger("10");
  TestStringToInteger("010");
  TestStringToInteger("a10");
  TestStringToInteger("+10w");
  TestStringToInteger("-1w0");

  return 0;
}

