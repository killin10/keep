//
// @file 158A.cc
// @brief Next Round
// 
// @version 1.0 
// @date Thu Oct 17 13:52:31 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

const int kMaxN = 51;

int main(int argc, char* argv[]) {
  int n = 0;
  int k = 0;
  int scores[kMaxN];

  std::cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    std::cin >> scores[i];
  }

  int next_round_count = 0;
  for (int i = 1; i <= n && scores[i] >= scores[k] && scores[i] > 0; ++i) {
    ++next_round_count;
  }

  std::cout << next_round_count << std::endl;

  return 0;
}

