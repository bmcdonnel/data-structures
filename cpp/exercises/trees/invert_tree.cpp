#include <iostream>
#include <stack>

#include "utils/tree_utils.h"

using namespace utils;

/**
 * This will recursively invert the tree; However, it's limited to
 * the application's available call stack space.
 */
void invert_tree(TreeNode* node)
{
  if (!node)
  {
    return;
  }

  invert_tree(node->left);
  invert_tree(node->right);

  TreeNode* temp = node->left;
  node->left = node->right;
  node->right = temp;
}

void invert_tree_stack(TreeNode* node)
{
  if (!node)
  {
    return;
  }

  std::stack<TreeNode*> node_stack;
  node_stack.push(node);

  while(!node_stack.empty())
  {
    TreeNode* n = node_stack.top();
    node_stack.pop();

    // swap the elements
    TreeNode* temp = n->left;
    n->left = n->right;
    n->right = temp;

    if (n->left)
    {
      node_stack.push(n->left);
    }

    if (n->right)
    {
      node_stack.push(n->right);
    }
  }

  return;
}

int main(int argc, char** argv)
{
  return 0;
}
