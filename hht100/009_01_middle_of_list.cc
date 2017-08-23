//
// @file 009_01_middle_of_list.cc
// @brief Find the middle element of the given list.
// 
// @version 1.0 
// @date Sun Jun  9 10:33:00 2013
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

ListNode* FindMiddleElement(ListNode* list) {
  assert(list != NULL);
  
  ListNode* fast_pos = list;
  ListNode* slow_pos = list;

  while (fast_pos != NULL) {
    if (fast_pos->next != NULL && fast_pos->next->next != NULL) {
      fast_pos = fast_pos->next->next;
      slow_pos = slow_pos->next;
    } else {
      break;
    }
  }

  return slow_pos;
}

void PrintList(ListNode* list) {
  for (ListNode* node = list; node != NULL; node = node->next) {
    std::cout << node->value << " ";
  }
  std::cout << std::endl;
}

void BuildListEven(ListNode** list) {
  *list = new ListNode(1);
  (*list)->next = new ListNode(2);
  (*list)->next->next = new ListNode(3);
  (*list)->next->next->next = new ListNode(4);
}

void BuildListOdd(ListNode** list) {
  *list = new ListNode(1);
  (*list)->next = new ListNode(2);
  (*list)->next->next = new ListNode(3);
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

  BuildListOdd(&list);
  PrintList(list);
  std::cout << "Middle element: " 
    << FindMiddleElement(list)->value << std::endl;
  DeleteList(&list);

  BuildListEven(&list);
  PrintList(list);
  std::cout << "Middle element: " 
    << FindMiddleElement(list)->value << std::endl;
  DeleteList(&list);

  return 0;
}

