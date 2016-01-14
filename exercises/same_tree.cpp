#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void same_tree(TreeNode* a, TreeNode* b)
{
  if (!a || !b)
  {
    // if either one is null, return whether they're the same
    return a == b;
  }

  return (a->val == b->val &&
          same_tree(a->left, b->left) &&
          same_tree(a->right, b->right));
}
