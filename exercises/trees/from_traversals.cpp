#include <iostream>
#include <vector>
#include <stack>

#include "utils/tree_utils.h"

using namespace utils;

TreeNode* build_from_pre_and_in_order(const std::vector<int>& pre_order,
                                      const std::vector<int>& in_order)
{
  return nullptr;
}

TreeNode* build_from_post_and_in_order(const std::vector<int>& post_order,
                                       const std::vector<int>& in_order)
{
  if (post_order.size() != in_order.size() ||
      post_order.size() == 0)
  {
    return nullptr;
  }

  int post_index = post_order.size() - 1;
  int in_index = in_order.size() - 1;

  std::stack<TreeNode*> s;

  TreeNode* root = new TreeNode(post_order[post_index]);
  post_index--;

  s.push(root);

  while (post_index >= 0)
  {
    if (in_order[in_index] == s.top()->val)
    {
      TreeNode* p = s.top();
      s.pop();

      in_index--;

      if (in_index < 0)
      {
        break;
      }

      if (s.size() && in_order[in_index] == s.top()->val)
      {
        continue;
      }

      p->left = new TreeNode(post_order[post_index]);
      post_index--;

      s.push(p->left);
    }
    else
    {
      TreeNode* p = new TreeNode(post_order[post_index]);
      post_index--;

      s.top()->right = p;
      s.push(p);
    }
  }

  return root;
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <2n+1 serialized tree values>" << std::endl;
    return 1;
  }

  int size = argc - 1;

  TreeNode* root = create_tree_node(&argv[1], size);

  std::vector<int> pre_order;
  std::vector<int> post_order;
  std::vector<int> in_order;

  pre_order_traversal(root, &pre_order);
  post_order_traversal(root, &post_order);
  in_order_traversal(root, &in_order);

  TreeNode* other_root = build_from_post_and_in_order(post_order, in_order);

  if (is_same_tree(root, other_root))
  {
    std::cout << "construction from post-order and in-order succeeded!" << std::endl;
  }
  else
  {
    std::cout << "construction from post-order and in-order failed!" << std::endl;
  }

  return 0;
}
