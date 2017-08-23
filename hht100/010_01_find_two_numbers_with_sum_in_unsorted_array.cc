//
// @file 010_01_find_two_numbers_with_sum_in_unsorted_array.cc
// @brief Find two numbers with given sum in the unsorted array.
// 
// @version 1.0 
// @date Wed Jun 12 22:16:51 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <tr1/unordered_map>

#include <assert.h>

void FindTwoNumbersWithSum(int array[], int size, int sum) {
  const int kNotAccessed = 0;
  const int kAccessed = 1;

  // build hash table
  std::tr1::unordered_map<int, int> num_map;
  for (int i = 0; i < size; ++i) {
    num_map.insert(std::make_pair(array[i], kNotAccessed));
  }

  // find
  bool found = false;
  std::tr1::unordered_map<int, int>::iterator it_num1 = num_map.begin();
  std::tr1::unordered_map<int, int>::iterator it_num2 = num_map.end();
  for (it_num1 = num_map.begin(); it_num1 != num_map.end(); ++it_num1) {
    it_num2 = num_map.find(sum - it_num1->first);
    if (it_num2 != num_map.end()
        && (kNotAccessed == it_num1->second 
          || kNotAccessed == it_num2->second)) {
      found = true;  // touch a found flag
      // touch access flag
      it_num1->second = kAccessed;
      it_num2->second = kAccessed;

      std::cout << "sum: " << sum << ", num1: " << it_num1->first
        << ", num2: " << it_num2->first << std::endl;
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

