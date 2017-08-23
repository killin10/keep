//
// @file path_in_binary_tree.cc
// @brief Find paths that the sum of nodes on the path 
//   equals to expected sum.
// 
// @version 1.0
// @date Thu May 30 18:48:56 2013
// 
// @copyright Copyright (C) 2013
// @author shiwei<shiwei2012@gmail.com>
//

#include <iostream>
#include <vector>

#include <assert.h>

struct BinaryTreeNode {
  int value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(int val, 
      BinaryTreeNode* lchild, BinaryTreeNode* rchild) {
    value = val;
    left = lchild;
    right = rchild;
  }

  ~BinaryTreeNode() {
    delete left;
    left = NULL;
    delete right;
    right = NULL;
  }
};

void FindPath(BinaryTreeNode* current_node, int expected_sum,
    std::vector<int>* path, int* current_sum) {
  assert(current_node != NULL);
  assert(path != NULL);
  assert(current_sum != NULL);

  *current_sum += current_node->value;
  path->push_back(current_node->value);

  bool is_leaf = (NULL == current_node->left) 
    && (NULL == current_node->right);
  if (is_leaf && *current_sum == expected_sum) {
    for (std::vector<int>::iterator it = path->begin(); 
        it != path->end(); ++it) {
      std::cout << *it<< " ";
    }
    std::cout << std::endl;
  }

  // visit left child
  if (current_node->left != NULL) {
    FindPath(current_node->left, expected_sum, path, current_sum);
  }
  // visit right child
  if (current_node->right != NULL) {
    FindPath(current_node->right, expected_sum, path, current_sum);
  }

  // return to parent node
  *current_sum -= current_node->value;
  path->pop_back();
}

void BuildTree(BinaryTreeNode** tree) {
  *tree = new BinaryTreeNode(10, NULL, NULL);
  BinaryTreeNode* node = *tree;
  node->left = new BinaryTreeNode(5, NULL, NULL);
  node->right = new BinaryTreeNode(12, NULL, NULL);
  node->left->left = new BinaryTreeNode(4, NULL, NULL);
  node->left->right = new BinaryTreeNode(7, NULL, NULL);
}

void DeleteTree(BinaryTreeNode** tree) {
  delete *tree;
  *tree = NULL;
}

int main(int argc, char* argv[]) {
  BinaryTreeNode* tree = NULL;
  BuildTree(&tree);

  int expected_sum = 22;
  std::vector<int> path;
  int current_sum = 0;

  FindPath(tree, expected_sum, &path, &current_sum);

  DeleteTree(&tree);

  return 0;
}


