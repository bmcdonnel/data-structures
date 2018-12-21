#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node)
{
  // sanity check node for null
  // check node->next for null cause that means node is the tail
  if (!node || !node->next)
  {
    return;
  }

  *node = *node->next;
}

void printList(ListNode* node)
{
  ListNode* thing = node;
  while(thing != nullptr)
  {
    std::cout << thing->val << "->";
    thing = thing->next;
  }
  std::cout << std::endl;
}

int main(int argc, char** argv)
{
  ListNode* head = new ListNode(0);

  ListNode* temp = head;
  for (int i = 1; i < 5; ++i)
  {
    temp->next = new ListNode(i);
    temp = temp->next;
  }

  temp->next = nullptr;

  // 0->1->2->3->4
  printList(head);

  // delete '2'
  deleteNode(head->next->next);

  // 0->1->3->4
  printList(head);
}
