//
// @file 009_kth_element_in_list.cc
// @brief Find the Kth element from bottom in the given list.
// 
// @version 1.0 
// @date Sun Jun  9 05:51:39 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

struct ListNode {
  int value;
  ListNode* next;

  ListNode(int val) : value(val), next(NULL) {}
  ListNode(int val, ListNode* n) : value(val), next(n) {}
  ~ListNode() { next = NULL; }
};

ListNode* FindKthElementToTail(ListNode* list, int k) {
  assert(list != NULL);
  assert(k >= 0);

  ListNode* k_pos = list;
  ListNode* it_pos = list;

  for (int i = 0; i < k; ++i) {
    if (it_pos->next != NULL) {
      it_pos = it_pos->next;
    } else {
      // list is too short
      return NULL;
    }
  }

  // move to the end of list
  while (it_pos->next != NULL) {
    it_pos = it_pos->next;
    k_pos = k_pos->next;
  }

  return k_pos;
}

void PrintList(ListNode* list) {
  for (ListNode* node = list; node != NULL; node = node->next) {
    std::cout << node->value << " ";
  }
  std::cout << std::endl;
}

void BuildList(ListNode** list) {
  *list = new ListNode(1);
  (*list)->next = new ListNode(2);
  (*list)->next->next = new ListNode(3);
  (*list)->next->next->next = new ListNode(4);
}

void DeleteList(ListNode** list) {
  ListNode* tmp_node = *list;
  ListNode* it_node = *list;

  while (it_node != NULL) {
    tmp_node = it_node;
    it_node = it_node->next;
    delete tmp_node;
    tmp_node = NULL;
  }

  *list = NULL;
}

int main(int argc, char* argv[]) {
  ListNode* list = NULL;
  BuildList(&list);

  PrintList(list);

  ListNode* node = NULL;
  for (int i = 0; i < 5; ++i) {
    node = FindKthElementToTail(list, i);
    if (NULL == node) {
      std::cout << "List is too short!" << std::endl;
    } else {
      std::cout << i << ": " << node->value << std::endl;
    }
  }

  DeleteList(&list);

  return 0;
}

