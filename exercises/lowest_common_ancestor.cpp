#include <iostream>
#include <set>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* node_a, TreeNode* node_b)
{
  if (node_a->val < root->val &&
      node_b->val < root->val)
  {
    // if both A and B are to the left of root; go to the left
    return lowest_common_ancestor(root->left, node_a, node_b);
  }
  else if (node_a->val > root->val &&
           node_b->val > root->val)
  {
    // if both A and B are to the right of root; go to the right
    return lowest_common_ancestor(root->right, node_a, node_b);
  }

  // A and B are on opposite sites of root; this is the lowest common ancestor
  return root;
}

int main(int argc, char** argv)
{
  return 0;
}
