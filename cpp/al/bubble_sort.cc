/*
 * @file bubble_sort.cc
 * @brief Bubble sort.
 * 
 * @version 1.0 
 * @date Sat May  4 17:12:38 2013
 * 
 * @copyright Copyright (C) 2013
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <iostream>

#include <assert.h>

void Swap(int* l, int* r) {
  assert(l != NULL && r != NULL);
  int temp = *l;
  *l = *r;
  *r = temp;
}

void PrintArray(int array[], int size) {
  assert(size >= 0);
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void BubbleSort(int array[], int size) {
  assert(size >= 0);
  bool swap_flag = false;
  for (int i = 0; i < size; ++i) {
    for (int j = size - 1; j > i; --j) {
      if (array[j - 1] > array[j]) {
        Swap(&array[j - 1], &array[j]);
        swap_flag = true;
      }
    }
    if (!swap_flag) {
      break;
    }
  }
}

int main(int argc, char* argv[]) {
  int array[10] = {3, 6, 2, 8, 34, 1, 9, 22, 13, 1};
  PrintArray(array, sizeof(array) / sizeof(int));
  BubbleSort(array, sizeof(array) / sizeof(int));
  PrintArray(array, sizeof(array) / sizeof(int));
  return 0;
}

