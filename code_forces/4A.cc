//
// @file 4A.cc
// @brief Watermelon
// 
// @version 1.0 
// @date Thu Oct 17 13:42:29 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

int main(int argc, char* argv[]) {
  int w = 0;
  std::cin >> w;

  int mod = w % 2;
  if (mod != 0) {
    std::cout << "NO" << std::endl;
  } else if (w == 2) {
    std::cout << "NO" << std::endl;
  } else {
    std::cout << "YES" << std::endl;
  }

  return 0;
}

