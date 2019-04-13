//
// @file max_subsequence_sum.cc
// @brief The max subsequence sum of an array.
// 
// @version 1.0
// @date Thu May 30 01:30:17 2013
// 
// @copyright Copyright (C) 2013
// @author shiwei<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

int MaxSubsequenceSum(int array[], int size) {
  assert(array != NULL);
  assert(size > 0);

  int max_sum = 0;
  int current_sum = 0;

  int max_start = 0;
  int max_end = 0;
  int start = 0;

  for (int i = 0; i < size; ++i) {
    current_sum += array[i];
    if (current_sum < 0) {
      current_sum = 0;
      start = i + 1;
    }
    if (current_sum > max_sum) {
      max_sum = current_sum;
      max_start = start;
      max_end = i;
    }
  }

  if (0 == max_sum) {
    // all elements are negative
    max_sum = array[0];
    for (int i = 1; i < size; ++i) {
      if (array[i] > max_sum) {
        max_sum = array[i];
      }
    }
  }

  std::cout << "max_start: " << max_start << ", "
    << "max_end: " << max_end << std::endl;

  return max_sum;
}

int main(int argc, char* argv[]) {
  int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
  int max_sum = MaxSubsequenceSum(array, sizeof(array) / sizeof(int));
  std::cout << "max subsequence sum: " << max_sum << std::endl;
  return 0;
}


