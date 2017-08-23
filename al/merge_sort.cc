//
// @file merge_sort.cc
// @brief Merge sort.
// 
// @version 1.0
// @date Thu May 23 00:03:45 2013
// 
// @copyright Copyright (C) 2013
// @author shiwei<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>
#include <stdlib.h>

void Swap(int* l, int* r);
void PrintArray(int array[], int size);
void MergeSort(int array[], int size);
void MSort(int array[], int tmp_array[], int left, int right);
void Merge(int array[], int tmp_array[], 
    int left_pos, int right_pos, int right_end);

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

void MergeSort(int array[], int size) {
  assert(size > 0);
  int* tmp_array = new int[size];
  if (tmp_array != NULL) {
    MSort(array, tmp_array, 0, size - 1);
    delete [] tmp_array;
  } else {
    std::cerr << "No space for tmp array!" << std::endl;
    exit(1);
  }
}

void MSort(int array[], int tmp_array[], int left, int right) {
  if (left < right) {
    int center = (left + right) / 2;
    MSort(array, tmp_array, left, center);
    MSort(array, tmp_array, center + 1, right);
    Merge(array, tmp_array, left, center + 1, right);
  }
}

/// @brief merge two parts of the array
///
/// @param array[]
/// @param tmp_array[] tmp space used to merge
/// @param left_pos start of the left half
/// @param right_pos start of the right half
/// @param right_end
void Merge(int array[], int tmp_array[], 
    int left_pos, int right_pos, int right_end) {
  assert(left_pos < right_end);

  int left_end = right_pos - 1;
  int tmp_pos = left_pos;
  int elements_nr = right_end - left_pos + 1;

  // main loop
  while (left_pos <= left_end && right_pos <= right_end) {
    if (array[left_pos] <= array[right_pos]) {
      tmp_array[tmp_pos++] = array[left_pos++];
    } else {
      tmp_array[tmp_pos++] = array[right_pos++];
    }
  }

  // copy rest of the first half
  while (left_pos <= left_end) {
    tmp_array[tmp_pos++] = array[left_pos++];
  }
  // copy rest of the second half
  while (right_pos <= right_end) {
    tmp_array[tmp_pos++] = array[right_pos++];
  }

  // copy tmp_array back
  for (int i = 0; i < elements_nr; ++i, --right_end) {
    array[right_end] = tmp_array[right_end];
  }
}

int main(int argc, char* argv[]) {
  int array[] = {23, 1, 6, 86, 123, 987, 21, 78, 58, 29, 85, 28};
  int size = sizeof(array) / sizeof(int);
  PrintArray(array, size);
  MergeSort(array, size);
  PrintArray(array, size);
  return 0;
}

