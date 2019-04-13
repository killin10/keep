//
// @file 118A.cc
// @brief String Task
// 
// @version 1.0 
// @date Thu Oct 17 14:25:19 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <string>

inline bool IsUpper(char c) {
  if (c >= 'A' && c <= 'Z') {
    return true;
  }
  return false;
}

inline char ToLower(char c) {
  if (IsUpper(c)) {
    return (c + 'a' - 'A');
  }
  return c;
}

inline bool IsVowel(char c) {
  char lc = ToLower(c);
  if (lc == 'a' || lc == 'o' || lc == 'y' 
      || lc == 'e' || lc == 'u' || lc == 'i') {
    return true;
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::string str;
  std::cin >> str;

  for (int i = 0; i < str.length(); ++i) {
    if (!IsVowel(str[i])) {
      std::cout << '.' << ToLower(str[i]);
    }
  }
  std::cout << std::endl;

  return 0;
}


