#include <iostream>
#include <unordered_map>

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

ListNode* remove_list_duplicates(ListNode* head)
{
  if (!head)
  {
    return head;
  }

  // the value at each key doesn't really matter, but
  // we might as well store the pointer to the node where the
  // value came from; all we really want is the O(1) look up
  std::unordered_map<int, ListNode*> seen;

  ListNode* current = head;
  ListNode* previous = nullptr;

  while(current)
  {
    const int value = current->val;

    // grab a point to the next node in case current is deleted
    ListNode* next = current->next;

    if (seen.find(value) != seen.end())
    {
      previous->next = current->next;

      delete current;
    }
    else
    {
      // add to the map of seen values
      seen[value] = current;

      // only move previous if nothing was removed
      previous = current;
    }

    current = next;
  }

  return head;
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <link list integer values>" << std::endl;
    return 1;
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

  head = remove_list_duplicates(head);

  print_list(head);

  return 0;
}
