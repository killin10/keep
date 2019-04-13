//
// @file min_k_elements.cc
// @brief Find k min elements from the input set.
//   We can find k min elements in O(nlogk) using heap or red-black tree.
// 
// @version 1.0
// @date Wed Jun  5 23:37:44 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <set>

#include <assert.h>

// Multiset is implemented using red-black tree,
// we use it as a max heap.
typedef std::multiset<int, std::greater<int> > IntHeap;

void FindMinElements(IntHeap *mins, int k, int array[], int size) {
  assert(mins != NULL);

  IntHeap::iterator it = mins->end();
  for (int i = 0; i < size; ++i) {
    if (mins->size() >= k) {
      it = mins->begin();  // max element in heap
      if (*it > array[i]) {
        mins->erase(it);
        mins->insert(array[i]);
      }
    } else {
      mins->insert(array[i]);
    }
  }
}

void PrintArray(int array[], int size) {
  assert(size >= 0);
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  int array[] = {1, 3, 2, 4, 8, 7, 5, 6};
  int kMin = 4;

  PrintArray(array, sizeof(array) / sizeof(int));

  IntHeap heap;
  FindMinElements(&heap, kMin, array, sizeof(array) / sizeof(int));

  std::cout << "The " << kMin << " minimum elements: ";
  for (IntHeap::iterator it = heap.begin(); it != heap.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}
