//
// @file in_place_merge_sort.cc
// @brief In-place merge sort.
// 
// @version 1.0
// @date Thu May 23 00:03:45 2013
// 
// @copyright Copyright (C) 2013
// @author shiwei<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

void PrintArray(int array[], int size);
void ReverseArray(int array[], int left, int right);
void SwapArray(int array[], int left_pos, int right_pos, int right_end);
void InplaceMerge(int array[], int left_pos, int right_pos, int right_end);
void MSort(int array[], int left, int right);
void InplaceMergeSort(int array[], int size);

void PrintArray(int array[], int size) {
  assert(size >= 0);
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void ReverseArray(int array[], int left, int right) {
  int tmp = 0;
  while (left < right) {
    tmp = array[left];
    array[left++] = array[right];
    array[right--] = tmp;
  }
}

// swap [array[left_pos], array[right_pos]) 
// and [array[right_pos], array[right_end]]
void SwapArray(int array[], int left_pos, int right_pos, int right_end) {
  ReverseArray(array, left_pos, right_pos - 1);
  ReverseArray(array, right_pos, right_end);
  ReverseArray(array, left_pos, right_end);
}

void InplaceMerge(int array[], int left_pos, int right_pos, int right_end) {
  int swap_index = 0;
  while (left_pos < right_pos && right_pos <= right_end) {
    swap_index = right_pos;
    while (left_pos < right_pos && array[left_pos] <= array[right_pos]) {
      ++left_pos;
    }
    while (right_pos <= right_end && array[right_pos] <= array[left_pos]) {
      ++right_pos;
    }
    SwapArray(array, left_pos, swap_index, right_pos - 1);
    left_pos += (right_pos - swap_index);
  }
}

void MSort(int array[], int left, int right) {
  if (left < right) {
    int center = (left + right) / 2;
    MSort(array, left, center);
    MSort(array, center + 1, right);
    InplaceMerge(array, left, center + 1, right);
  }
}

void InplaceMergeSort(int array[], int size) {
  assert(size > 0);
  MSort(array, 0, size - 1);
}

int main(int argc, char* argv[]) {
  int array[] = {23, 1, 6, 86, 123, 987, 21, 78, 58, 29, 85, 28};
  int size = sizeof(array) / sizeof(int);
  PrintArray(array, size);
  InplaceMergeSort(array, size);
  PrintArray(array, size);
  return 0;
}

