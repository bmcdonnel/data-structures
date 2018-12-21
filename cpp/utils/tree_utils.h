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

TreeNode* create_tree_node(char* const* array, const int size, const int i = 0)
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

bool is_same_tree(TreeNode const* a, TreeNode const* b)
{
  if (!a || !b)
  {
    // if either one is null, return whether they're the same
    return a == b;
  }

  return (a->val == b->val &&
          is_same_tree(a->left, b->left) &&
          is_same_tree(a->right, b->right));
}

void level_traversal(TreeNode const* node, std::vector<std::vector<int>>& result, const int depth = 0)
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
  level_traversal(node->left, result, depth + 1);
  level_traversal(node->right, result, depth + 1);
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

void pre_order_traversal(TreeNode* node, std::vector<int>* traversal)
{
  if (!node)
  {
    return;
  }

  traversal->push_back(node->val);

  pre_order_traversal(node->left, traversal);

  pre_order_traversal(node->right, traversal);
}

void post_order_traversal(TreeNode* node, std::vector<int>* traversal)
{
  if (!node)
  {
    return;
  }

  post_order_traversal(node->left, traversal);

  post_order_traversal(node->right, traversal);

  traversal->push_back(node->val);
}

} // namespace utils

#endif

