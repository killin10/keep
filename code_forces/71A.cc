//
// @file 71A.cc
// @brief Way Too Long Words
// 
// @version 1.0 
// @date Thu Oct 17 14:06:55 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int kTooLongLength = 10;

std::string ConvToString(int n) {
  std::stringstream ss;
  ss << n;
  std::string str_n;
  ss >> str_n;
  return str_n;
}

int main(int argc, char* argv[]) {
  int n = 0;
  std::vector<std::string> strings;
  std::string word;
  std::string abbr;

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> word;
    strings.push_back(word);
  }

  for (std::vector<std::string>::iterator it = strings.begin();
      it != strings.end(); ++it) {
    if (it->length() <= kTooLongLength) {
      std::cout << *it << std::endl;
    } else {
      abbr = it->at(0);
      abbr += ConvToString(it->length() - 2);
      abbr += it->at(it->length() - 1);
      std::cout << abbr << std::endl;
    }
  }

  return 0;
}

