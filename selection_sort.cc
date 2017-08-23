/*
 * @file selection_sort.cc
 * @brief Simple selection sort.
 * 
 * @version 1.0 
 * @date Sat May  4 17:47:02 2013
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

void SelectionSort(int array[], int size) {
  assert(size >= 0);
  int min = 0;
  for (int i = 0; i < size - 1; ++i) {
    min = i;
    for (int j = i + 1; j < size; ++j) {
      if (array[min] > array[j]) {
        min = j;
      }
    }
    if (min != i) {
      Swap(&array[min], &array[i]);
    }
  }
}

int main(int argc, char* argv[]) {
  int array[10] = {3, 6, 2, 8, 34, 1, 9, 22, 13, 1};
  PrintArray(array, sizeof(array) / sizeof(int));
  SelectionSort(array, sizeof(array) / sizeof(int));
  PrintArray(array, sizeof(array) / sizeof(int));
  return 0;
}

