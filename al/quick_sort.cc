//
// @file quick_sort.cc
// @brief Quick sort.
// 
// @version 1.0
// @date Sun May 26 17:27:48 2013
// 
// @copyright Copyright (C) 2013
// @author shiwei<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>
#include <stdlib.h>

void Swap(int* l, int* r);
void PrintArray(int array[], int size);
void InsertionSort(int array[], int size);
int Median3(int array[], int left, int right);
void QSort(int array[], int left, int right);
void QuickSort(int array[], int size);

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
  int pos = 0;
  int temp = 0;
  for (int i = 1; i < size; ++i) {
    if (array[i] < array[i - 1]) {
      temp = array[i];
      for (int j = i - 1; i >= 0; --j) {
        if (array[j] > temp) {
          array[j + 1] = array[j];
        } else {
          pos = j + 1;
          break;
        }
      }
      array[pos] = temp;
    }
  }
}

/// @brief Return median of left, center, and right,
///        order these and hide the pivot.
///
/// @param array[]
/// @param left
/// @param right
///
/// @return 
int Median3(int array[], int left, int right) {
  int center = (left + right) / 2;

  if (array[left] > array[center]) {
    Swap(array + left, array + center);
  }
  if (array[left] > array[right]) {
    Swap(array + left, array + right);
  }
  if (array[center] > array[right]) {
    Swap(array + center, array + right);
  }

  // Invariant: array[left] <= array[center] <= array[right]

  Swap(array + center, array + right - 1);  // Hide pivot
  return array[right - 1];  // Return the pivot
}

const int kCutoffRange = 3;

void QSort(int array[], int left, int right) {
  if (left + kCutoffRange <= right) {
    int pivot = Median3(array, left, right);
    int i = left;
    int j = right - 1;
    for (; ; ) {
      while (array[++i] < pivot) {}
      while (array[--j] > pivot) {}
      if (i < j) {
        Swap(array + i, array + j);
      } else {
        break;
      }

    }
    Swap(array + i, array + right - 1);  // Restore pivot

    QSort(array, left, i - 1);
    QSort(array, i + 1, right);
  } else {
    // Do an insertion sort on the subarray
    InsertionSort(array + left, right - left + 1);
  }
}

void QuickSort(int array[], int size) {
  assert(size > 0);
  QSort(array, 0, size - 1);
}

int main(int argc, char* argv[]) {
  int array[] = {23, 1, 6, 86, 123, 987, 21, 78, 58, 29, 85, 28};
  int size = sizeof(array) / sizeof(int);
  PrintArray(array, size);
  QuickSort(array, size);
  PrintArray(array, size);
  return 0;
}

