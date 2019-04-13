//
// @file 006_is_binary_search_tree.cc
// @brief Whether a given sequence is the 
//   post-order traversal of a binary search tree.
// 
// @version 1.0 
// @date Sun Jun  9 01:37:07 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

bool IsBinarySearchTree(int array[], int left, int right) {
  assert(left <= right);

  if (left == right) {
    // only one node
    return true;
  }

  int root_node_value = array[right];

  int less_pos = left;
  while (less_pos < right && array[less_pos] < root_node_value) {
    ++less_pos;
  }
  --less_pos;

  int greater_pos = less_pos + 1;
  while (greater_pos < right && array[greater_pos] > root_node_value) {
    ++greater_pos;
  }
  --greater_pos;

  if (greater_pos != right - 1 && greater_pos != right) {
    // invalid sequence
    return false;
  }

  // valid sequence

  // check left subtree
  bool valid_left = true;
  if (less_pos >= left) {
    valid_left = IsBinarySearchTree(array, left, less_pos);
  }

  // check right subtree
  bool valid_right = true;
  if (greater_pos <= right - 1) {
    valid_right = IsBinarySearchTree(array, greater_pos, right - 1);
  }

  return valid_left && valid_right;
}

void PrintArray(int array[], int size) {
  assert(size >= 0);
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  int array1[] = {5, 7, 6, 9, 11, 10, 8};
  int size1 = sizeof(array1) / sizeof(int);
  PrintArray(array1, size1);
  if (IsBinarySearchTree(array1, 0, size1 - 1)) {
    std::cout << "Valid sequence!" << std::endl;
  } else {
    std::cout << "Invalid sequence!" << std::endl;
  }

  int array2[] = {7, 4, 6, 5};
  int size2 = sizeof(array2) / sizeof(int);
  PrintArray(array2, size2);
  if (IsBinarySearchTree(array2, 0, size2 - 1)) {
    std::cout << "Valid sequence!" << std::endl;
  } else {
    std::cout << "Invalid sequence!" << std::endl;
  }

  return 0;
}

