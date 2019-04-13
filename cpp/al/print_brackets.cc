//
// @file print_brackets.cc
// @brief Print all valid combinations of n-pairs of parentheses.
// 
// @version 1.0 
// @date Fri Sep 13 19:37:34 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <string.h>

#include <iostream>

void PrintBrackets(char* begin, char* cur, int pairs, int open, int close) {
  if (open == pairs && close == pairs) {
    std::cout << begin << std::endl;
    return;
  }

  if (open < pairs) {
    *cur = 'a';
    PrintBrackets(begin, cur + 1, pairs, open + 1, close);
  }

  if (close < open) {
    *cur = 'b';
    PrintBrackets(begin, cur + 1, pairs, open, close + 1);
  }
}

int main(int argc, char* argv[]) {
  int pairs = 0;
  std::cin >> pairs;

  char* buf = new char[pairs * 2 + 1];
  memset(buf, 0, pairs * 2 + 1);
  PrintBrackets(buf, buf, pairs, 0, 0);
  delete [] buf;

  buf = NULL;
  return 0;
}
