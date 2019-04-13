/*
 * @file reverse_linked_list.cc
 * @brief Reverse a linked list.
 * 
 * @version 1.0 
 * @date Fri May  3 11:29:21 2013
 * 
 * @copyright Copyright (C) 2013
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <iostream>

struct LinkedNode {
  LinkedNode() : data(0), next(NULL) {}

  int data;
  LinkedNode* next;
};

void ReverseLinkedList(LinkedNode** list) {
  if (list == NULL || *list == NULL) {
      return;
  }

  LinkedNode* last = NULL;
  LinkedNode* current = *list;
  LinkedNode* next = NULL;

  while (current != NULL) {
      next = current->next;
      current->next = last;
      last = current;
      current = next;
  }

  *list = last;
}

LinkedNode* ReverseLinkedListRecursiveInternal(
        LinkedNode* list, LinkedNode* last) {
  if (list == NULL) {
    return last;
  }

  LinkedNode* next = list->next;
  list->next = last;
  return ReverseLinkedListRecursiveInternal(next, list);
}

void ReverseLinkedListRecursive(LinkedNode** list) {
  if (list == NULL || *list == NULL) {
      return;
  }

  *list = ReverseLinkedListRecursiveInternal(*list, NULL);
}

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

int main(int argc, char* argv[]) {
  LinkedNode* list = NULL;
  LinkedNode* node = NULL;

  for (int i = 0; i < 3; ++i) {
    node = new LinkedNode();
    node->data = i;
    node->next = list;
    list = node;
  }
  PrintLinkedList(list);

  ReverseLinkedList(&list);
  PrintLinkedList(list);

  ReverseLinkedListRecursive(&list);
  PrintLinkedList(list);

  ReleaseLinkedList(&list);
  return 0;
}

