#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* head)
{
  ListNode* current = head;

  while (current != nullptr)
  {
    std::cout << current->val;

    if (current->next != nullptr)
    {
      std::cout << " -> ";
    }

    current = current->next;
  }

  std::cout << std::endl;
}

ListNode* reverse_linked_list(ListNode* head)
{
  if (!head)
  {
    return head;
  }

  ListNode* current = head;
  ListNode* previous = nullptr;

  while (current)
  {
    ListNode* next = current->next;

    current->next = previous;

    previous = current;
    current = next;
  }

  return previous;
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <link list integer values>" << std::endl;
  }

  int size = argc - 1;

  ListNode* head = new ListNode(std::atoi(argv[1]));

  ListNode* previous = head;
  for (int i = 0; i < size - 1; ++i)
  {
    int val = std::atoi(argv[i + 2]);

    ListNode* current = new ListNode(val);
    previous->next = current;
    previous = current;
  }

  print_list(head);

  head = reverse_linked_list(head);

  print_list(head);

  return 0;
}
