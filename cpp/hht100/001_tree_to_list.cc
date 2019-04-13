//
// @file tree_to_list.cc
// @brief Convert a binary search tree to 
//   a sorted double linked list.
// 
// @version 1.0
// @date Fri May 31 00:00:55 2013
// 
// @copyright Copyright (C) 2013
// @author shiwei<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

struct BinaryTreeNode;

enum Direction {
  kLeft,
  kRight
};

// Convert a binary search tree to double-linked list by in-order traversal.
BinaryTreeNode* ConvertNode(BinaryTreeNode* last, BinaryTreeNode* current);
BinaryTreeNode* ConvertToListInOrder(BinaryTreeNode* tree);

// Convert a binary search tree to double-linked list recursively.
BinaryTreeNode* ConvertNode(BinaryTreeNode* current, Direction direction);
BinaryTreeNode* ConvertToList(BinaryTreeNode* tree);

void BuildTree(BinaryTreeNode** tree);
void DeleteList(BinaryTreeNode** list_head);


struct BinaryTreeNode {
  int value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(int val) {
    value = val;
    left = NULL;
    right = NULL;
  }

  ~BinaryTreeNode() {
    delete left;
    left = NULL;
    delete right;
    right = NULL;
  }
};

BinaryTreeNode* ConvertNode(BinaryTreeNode* last, BinaryTreeNode* current) {
  assert(last != NULL);

  if (current != NULL) {
    last = ConvertNode(last, current->left);
    assert(last != NULL);
    last->right = current;
    current->left = last;
    return ConvertNode(current, current->right);
  }

  return last;
}

BinaryTreeNode* ConvertToListInOrder(BinaryTreeNode* tree) {
  BinaryTreeNode head(0);  // head node
  ConvertNode(&head, tree);

  BinaryTreeNode* first_node = head.right;
  head.left = NULL;
  head.right = NULL;

  first_node->left = NULL;
  return first_node;
}

BinaryTreeNode* ConvertNode(BinaryTreeNode* current, Direction direction) {
  assert(kLeft == direction || kRight == direction);

  if (NULL == current->left && NULL == current->right) {
    return current;
  }

  if (current->left != NULL) {
    BinaryTreeNode* last = ConvertNode(current->left, kLeft);
    last->right = current;
    current->left = last;
  }

  if (current->right != NULL) {
    BinaryTreeNode* next = ConvertNode(current->right, kRight);
    current->right = next;
    next->left = current;
  }

  BinaryTreeNode* node = current;
  if (kLeft == direction) {
    while (node->right != NULL) {
      node = node->right;
    }
  } else if (kRight == direction) {
    while (node->left != NULL) {
      node = node->left;
    }
  } else {
    // never reach here
  }

  return node;
}

BinaryTreeNode* ConvertToList(BinaryTreeNode* tree) {
  return ConvertNode(tree, kRight);
}

void BuildTree(BinaryTreeNode** tree) {
  *tree = new BinaryTreeNode(10);
  BinaryTreeNode* node = *tree;
  node->left = new BinaryTreeNode(6);
  node->left->left = new BinaryTreeNode(4);
  node->left->right = new BinaryTreeNode(8);
  node->right = new BinaryTreeNode(14);
  node->right->left = new BinaryTreeNode(12);
  node->right->right = new BinaryTreeNode(16);
}

void DeleteList(BinaryTreeNode** list_head) {
  BinaryTreeNode* tmp = NULL;
  for (BinaryTreeNode* node = *list_head; node != NULL; node = tmp) {
    tmp = node->right;
    node->left = NULL;
    node->right = NULL;
    delete node;
  }
  *list_head = NULL;
}

int main(int argc, char* argv[]) {
  BinaryTreeNode* tree = NULL;

  // Convert by an in-order traversal
  BuildTree(&tree);

  BinaryTreeNode* head = ConvertToListInOrder(tree);
  for (BinaryTreeNode *node = head; node != NULL; node = node->right) {
    std::cout << node->value << " ";
  }
  std::cout << std::endl;

  BinaryTreeNode* last = head;
  for ( ; last->right != NULL; last = last->right) {
    // leave blank intentionally
  }

  for (BinaryTreeNode* node = last; node != NULL; node = node->left) {
    std::cout << node->value << " ";
  }
  std::cout << std::endl;

  DeleteList(&head);

  // convert recursively
  BuildTree(&tree);

  head = ConvertToList(tree);
  for (BinaryTreeNode *node = head; node != NULL; node = node->right) {
    std::cout << node->value << " ";
  }
  std::cout << std::endl;

  last = head;
  for ( ; last->right != NULL; last = last->right) {
    // leave blank intentionally
  }

  for (BinaryTreeNode* node = last; node != NULL; node = node->left) {
    std::cout << node->value << " ";
  }
  std::cout << std::endl;

  DeleteList(&head);

  return 0;
}

