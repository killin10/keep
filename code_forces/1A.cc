//
// @file 1A.cc
// @brief Theatre Square
// 
// @version 1.0 
// @date Wed Oct 16 23:47:36 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

int main(int argc, char* argv[]) {
  int n = 0;
  int m = 0;
  int a = 0;

  std::cin >> n >> m >> a;

  int cnt_n = n / a;
  if (n % a != 0) {
    ++cnt_n;
  }
  int cnt_m = m / a;
  if (m % a != 0) {
    ++cnt_m;
  }

  std::cout << (long long) cnt_n * cnt_m << std::endl;

  return 0;
}

