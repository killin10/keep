//
// @file 011_bst_mirror.cc
// @brief Mirror the BST(swap the left subtree and the right subtree).
// 
// @version 1.0 
// @date Wed Jun 12 22:57:56 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <queue>

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

void MirrorRecursively(BinaryTreeNode* tree) {
  if (tree != NULL) {
    MirrorRecursively(tree->left);
    MirrorRecursively(tree->right);
    BinaryTreeNode* tmp_node = tree->left;
    tree->left = tree->right;
    tree->right = tmp_node;
  }
}

void MirrorIteratively(BinaryTreeNode* tree) {
  assert(tree != NULL);

  std::queue<BinaryTreeNode*> nodes;
  nodes.push(tree);

  BinaryTreeNode* node = NULL;
  BinaryTreeNode* tmp_node = NULL;
  while (!nodes.empty()) {
    node = nodes.front();
    nodes.pop();

    tmp_node = node->left;
    node->left = node->right;
    node->right = tmp_node;

    if (node->left != NULL) {
      nodes.push(node->left);
    }
    if (node->right != NULL) {
      nodes.push(node->right);
    }
  }
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
  MirrorRecursively(tree);
  PrintTree(tree, 0);
  MirrorIteratively(tree);
  PrintTree(tree, 0);
  DeleteTree(&tree);

  return 0;
}

