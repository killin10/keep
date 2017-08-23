//
// @file 158B.cc
// @brief Taxi
// 
// @version 1.0 
// @date Thu Oct 17 14:59:15 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <algorithm>

const int kMaxPerCar = 4;
const int kMaxGroups = 100000;

int main(int argc, char* argv[]) {
  int n = 0;
  int s[kMaxGroups];
  
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
  }

  std::sort(s, s + n);

  int car_count = 0;
  int in_car = 0;

  int left = 0;
  int right = n - 1;
  while (left <= right) {
    in_car = s[right--];
    while (left <= right && in_car + s[left] <= kMaxPerCar) {
      in_car += s[left++];
      if (in_car == kMaxPerCar) {
        break;
      }
    }
    ++car_count;
  }

  std::cout << car_count << std::endl;
  
  return 0;
}

