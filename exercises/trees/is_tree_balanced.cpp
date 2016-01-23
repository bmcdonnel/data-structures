#include <iostream>

bool is_balanced(TreeNode* node)
{
  if (!node)
  {
    return true;
  }

  if (!is_balanced(node->left))
  {
    return false;
  }

  if (!is_balanced(node->right))
  {
    return false;
  }

  int leftHeight = height(node->left);
  int rightHeight = height(node->right);

  int balance_factor = rightHeight - leftHeight;

  return (balance_factor > -1 && balance_factor < 1);
}

