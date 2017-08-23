/*
 * @file loop_linked_list.cc
 * @brief Whether the list has a loop?
 * 
 * @version 1.0 
 * @date Fri May  3 11:29:21 2013
 * 
 * @copyright Copyright (C) 2013
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <iostream>

#include <cassert>

struct LinkedNode {
  LinkedNode() : data(0), next(NULL) {}

  int data;
  LinkedNode* next;
};

void PrintLinkedList(LinkedNode* list) {
  LinkedNode* node = NULL;

  for (node = list; node != NULL; node = node->next) {
    std::cout << node->data << " ";
  }
  std::cout << std::endl;
}

void ReleaseLinkedList(LinkedNode** list) {
    LinkedNode* node = NULL;

    while (*list != NULL) {
        node = *list;
        *list = node->next;
        delete node;
    }
}

bool HasLoop(LinkedNode* list, int quick_inc, int slow_inc) {
  LinkedNode* quick_pointer = list;
  LinkedNode* slow_pointer = list;
  while (quick_pointer != NULL && slow_pointer != NULL) {
    for (int i = 0; i < quick_inc; ++i) {
      quick_pointer = quick_pointer->next;
    }
    for (int i = 0; i < slow_inc; ++i) {
      slow_pointer = slow_pointer->next;
    }
    if (quick_pointer == slow_pointer) {
      break;
    }
  }
  return (quick_pointer == NULL || slow_pointer == NULL) ? false : true;
}

int main(int argc, char* argv[]) {
  LinkedNode* list = NULL;
  LinkedNode* last = NULL;

  list = new LinkedNode();
  list->data = 0;
  list->next = NULL;
  last = list;
  for (int i = 1; i < 12; ++i) {
    last->next = new LinkedNode();
    last->next->data = i;
    last->next->next = NULL;
    last = last->next;
  }

  if (HasLoop(list, 2, 1)) {
    std::cout << "Has Loop!" << std::endl;
  } else {
    std::cout << "No Loop!" << std::endl;
  }

  LinkedNode* node = list;
  for (int i = 0; i < 6; ++i) {
    node = node->next;
  }
  last->next = node;

  if (HasLoop(list, 2, 1)) {
    std::cout << "Has Loop!" << std::endl;
  } else {
    std::cout << "No Loop!" << std::endl;
  }

  return 0;
}

