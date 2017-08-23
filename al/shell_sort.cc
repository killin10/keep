/*
 * @file shell_sort.cc
 * @brief Shell sort.
 * 
 * @version 1.0 
 * @date Tue May 21 22:45:41 2013
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

void ShellSort(int array[], int size) {
  assert(size > 0);

  int i = 0;
  int j = 0;
  int increment = 0;
  int tmp = 0;

  for (increment = size / 2; increment > 0; increment /= 2) {
    for (i = increment; i < size; ++i) {
      tmp = array[i];
      for (j = i; j >= increment; j -= increment) {
        if (tmp < array[j - increment]) {
          array[j] = array[j - increment];
        } else {
          break;
        }
      }
      array[j] = tmp;
    }
  }
}

int main(int argc, char* argv[]) {
  int array[] = {23, 1, 6, 86, 123, 987, 21, 78, 58, 29, 85, 28};
  int size = sizeof(array) / sizeof(int);
  PrintArray(array, size);
  ShellSort(array, size);
  PrintArray(array, size);
  return 0;
}

