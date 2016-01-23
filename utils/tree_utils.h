#ifndef TREE_UTILS_H_
#define TREE_UTILS_H_

#include <iostream>
#include <iomanip>

namespace utils {

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create_tree_node(char** array, int size, int i)
{
  if (i >= size)
  {
    return nullptr;
  }

  if (array[i] && array[i][0] == 'x')
  {
    return nullptr;
  }

  int value = std::atoi(array[i]);

  TreeNode* node = new TreeNode(value);

  node->left = create_tree_node(array, size, (2 * i) + 1);
  node->right = create_tree_node(array, size, (2 * i) + 2);

  return node;
}

void print_binary_tree(TreeNode* node, const int indent = 0)
{
  if (!node)
  {
    return;
  }

  if (node->left)
  {
    print_binary_tree(node->left, indent + 4);
  }

  if (node->right)
  {
    print_binary_tree(node->right, indent + 4);
  }

  if (indent)
  {
    std::cout << std::setw(indent) << ' ';
  }

  std::cout << node->val << std::endl;

}

} // namespace utils

#endif

