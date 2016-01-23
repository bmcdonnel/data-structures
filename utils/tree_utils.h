#ifndef TREE_UTILS_H_
#define TREE_UTILS_H_

#include <iostream>
#include <iomanip>
#include <vector>

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

void level_traversal(const TreeNode* node, const int depth, std::vector<std::vector<int>>& result)
{
  if (!node)
  {
    return;
  }

  if (depth >= result.size())
  {
    result.push_back(std::vector<int>());
  }

  result[depth].push_back(node->val);
  level_traversal(node->left, depth + 1, result);
  level_traversal(node->right, depth + 1, result);
}

void in_order_traversal(TreeNode* node, std::vector<int>* traversal)
{
  if (!node)
  {
    return;
  }

  in_order_traversal(node->left, traversal);

  traversal->push_back(node->val);

  in_order_traversal(node->right, traversal);
}

void pre_order_traversal(TreeNode* node)
{
}

void post_order_traversal(TreeNode* node)
{
}

} // namespace utils

#endif

