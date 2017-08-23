/*
 * @file insertion_sort.cc
 * @brief Simple insertion sort.
 * 
 * @version 1.0 
 * @date Sat May  4 19:32:40 2013
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

void InsertionSort(int array[], int size) {
  assert(size >= 0);
  int i = 0;
  int j = 0;
  int tmp = 0;
  for (i = 1; i < size; ++i) {
    tmp = array[i];
    for (j = i; j > 0 && array[j - 1] > tmp; --j) {
      array[j] = array[j - 1];
    }
    array[j] = tmp;
  }
}

int main(int argc, char* argv[]) {
  int array[10] = {3, 6, 2, 8, 34, 1, 9, 22, 13, 1};
  PrintArray(array, sizeof(array) / sizeof(int));
  InsertionSort(array, sizeof(array) / sizeof(int));
  PrintArray(array, sizeof(array) / sizeof(int));
  return 0;
}

