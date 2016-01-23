#include <stack>

int height(TreeNode* node)
{
  if (!node)
  {
    return 0;
  }

  int leftHeight = height(node->left);
  int rightHeight = height(node->right);

  if (leftHeight > rightHeight)
  {
    return leftHeight + 1;
  }
  else
  {
    return rightHeight + 1;
  }
}

int maxDepth(TreeNode* root)
{
  return height(root);
}
