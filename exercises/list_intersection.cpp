#include <iostream>

ListNode* find_intersection_node(ListNode* node_a, ListNode* node_b)
{
  ListNode* i = node_a;
  ListNode* j = node_b;

  while(i != nullptr && j != nullptr && i != j)
  {
    i = i->next;
    j = j->next;

    if (i == j)
    {
      return i;
    }

    // if either pointer reaches the end,
    // reset it to the front of the opposite list
    // once both pointers reset to their opposite lists,
    // both will be the same distance away from any 
    // potential intersection
    if (i == nullptr) { i = node_b; }
    if (j == nullptr) { j = node_a; }
  }

  return i;
}

int main(int argc, char** argv)
{
  return 0;
}

