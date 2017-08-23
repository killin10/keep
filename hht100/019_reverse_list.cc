//
// @file 019_reverse_list.cc
// @brief Reverse a linked list.
// 
// @version 1.0 
// @date 四  9月 19 16:57:33 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

struct ListNode {
  int data;
  ListNode* next;
  ListNode(int d) {
    data = d;
  }
};

ListNode* ReverseIteratively(ListNode* head) {
  ListNode* prev = NULL;
  ListNode* cur = head;
  ListNode* rhead = NULL;
  while (cur != NULL) {
    ListNode* next = cur->next;
    if (next == NULL) {
      rhead = cur;
    }
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return rhead;
}

ListNode* BuildList() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  return head;
}

void PrintList(ListNode* head) {
  while (head != NULL) {
    std::cout << head->data << "\t";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  ListNode* list = BuildList();
  PrintList(list);
  list = ReverseIteratively(list);
  PrintList(list);
  return 0;
}


