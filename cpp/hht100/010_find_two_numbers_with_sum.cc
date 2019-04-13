//
// @file 010_find_two_numbers_with_sum.cc
// @brief Find two numbers with the given sum in the array.
// 
// @version 1.0 
// @date Tue Jun 11 09:17:31 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

void FindTwoNumbersWithSum(int array[], int size, int sum) {
  assert(size > 0);

  int left = 0;
  int right = size - 1;
  int tmp_sum = 0;
  bool found = false;
  while (left < right) {
    tmp_sum = array[left] + array[right];
    if (tmp_sum > sum) {
      --right;
    } else if (tmp_sum < sum) {
      ++left;
    } else {
      found = true;
      std::cout << "sum: " << sum << ", "
        << "num1: " << array[left] << ", "
        << "num2: " << array[right] << std::endl;
      ++left;  // or --right;
    }
  }

  if (!found) {
    std::cout << "no numbers found with sum " << sum << std::endl;
  }
}

void PrintArray(int array[], int size) {
  assert(size >= 0);
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  int array[] = {1, 2, 4, 7, 11, 14};
  int size = sizeof(array) / sizeof(int);

  PrintArray(array, size);

  int sum = 15;
  FindTwoNumbersWithSum(array, size, sum);

  return 0;
}

