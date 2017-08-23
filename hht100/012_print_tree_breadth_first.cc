//
// @file 012_print_tree_breadth_first.cc
// @brief Print a tree from top to bottom(breadth first).
// 
// @version 1.0 
// @date Thu Jun 13 10:22:59 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <deque>

#include <assert.h>

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

void PrintTreeFromTopToBottom(BinaryTreeNode* tree) {
  assert(tree != NULL);

  std::deque<BinaryTreeNode*> nodes;
  nodes.push_back(tree);

  BinaryTreeNode* node = NULL;
  while (!nodes.empty()) {
    node = nodes.front();
    nodes.pop_front();

    std::cout << node->value << "\t";

    if (node->left != NULL) {
      nodes.push_back(node->left);
    }
    if (node->right != NULL) {
      nodes.push_back(node->right);
    }
  }

  std::cout << std::endl;
}

void BuildTree(BinaryTreeNode** tree) {
  *tree = new BinaryTreeNode(8);
  BinaryTreeNode* node = *tree;
  node->left = new BinaryTreeNode(6);
  node->right = new BinaryTreeNode(10);
  node->left->left = new BinaryTreeNode(5);
  node->left->right = new BinaryTreeNode(7);
  node->right->left = new BinaryTreeNode(9);
  node->right->right = new BinaryTreeNode(11);
}

void DeleteTree(BinaryTreeNode** tree) {
  delete *tree;
  *tree = NULL;
}

void PrintTree(BinaryTreeNode* tree, int level) {
  assert(level >= 0);

  if (tree != NULL) {
    for (int i = 0; i < level; ++i) {
      std::cout << "\t";
    }
    std::cout << tree->value << std::endl;
    PrintTree(tree->left, level + 1);
    PrintTree(tree->right, level + 1);
  }
}

int main(int argc, char* argv[]) {
  BinaryTreeNode* tree = NULL;

  BuildTree(&tree);
  PrintTree(tree, 0);
  PrintTreeFromTopToBottom(tree);
  DeleteTree(&tree);

  return 0;
}

