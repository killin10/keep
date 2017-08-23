//
// @file heap_sort.cc
// @brief Heap sort.
// 
// @version 1.0
// @date Mon Jun  3 22:44:33 2013
// 
// @copyright Copyright (C) 2013
// @author shiwei<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

inline void Swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void PrintArray(int array[], int size) {
  assert(size >= 0);
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

inline int LeftChild(int i) {
  return 2 * i + 1;
}

void PercDown(int array[], int i, int size) {
  int child = 0;
  int tmp = 0;

  for (tmp = array[i]; LeftChild(i) < size; i = child) {
    child = LeftChild(i);
    if (child != size - 1 && array[child + 1] >  array[child]) {
      ++child;
    }
    if (tmp < array[child]) {
      array[i] = array[child];
    } else {
      break;
    }
  }
  array[i] = tmp;
}

void HeapSort(int array[], int size) {
  // Build heap.
  for (int i = size / 2; i >= 0; --i) {
    PercDown(array, i, size);
  }

  // Sort.
  for (int i = size - 1; i > 0; --i) {
    Swap(&array[0], &array[i]);  // DeleteMax
    PercDown(array, 0, i);
  }
}

int main(int argc, char* argv[]) {
  int array[] = {23, 1, 6, 86, 123, 987, 21, 78, 58, 29, 85, 28};
  int size = sizeof(array) / sizeof(int);
  PrintArray(array, size);
  HeapSort(array, size);
  PrintArray(array, size);
  return 0;
}

