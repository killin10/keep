/*
 * @file binary_search.cc
 * @brief Binary search.
 * 
 * @version 1.0 
 * @date Fri May  3 16:05:20 2013
 * 
 * @copyright Copyright (C) 2013
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <iostream>

int BinarySearch(int array[], int size, int value) {
  int low = 0;
  int high = size - 1;
  int middle = 0;

  while (low <= high) {
    middle = ((high - low) / 2) + low;
    if (array[middle] == value) {
        return middle;
    } else if (array[middle] > value) {
        high = middle - 1;
    } else {
        low = middle + 1;
    }
  }

  return -1;
}

int main(int argc, char* argv[]) {
  int array[10] = {1, 3, 5, 6, 8, 9, 11, 12, 14, 15};
  for (int i = 0; i < 10; ++i) {
      std::cout << i << ":" << array[i] << " ";
  }
  std::cout << std::endl;

  int pos = 0;
  for (int i = 0; i < 20; ++i) {
    pos = BinarySearch(array, 10, i);
    std::cout << i << " found on position " << pos << std::endl;
  }

  return 0;
}

