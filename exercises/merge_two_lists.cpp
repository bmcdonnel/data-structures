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

ListNode* merge_lists(ListNode* head_a, ListNode* head_b)
{
  if (!head_a)
  {
    return head_b;
  }

  if (!head_b)
  {
    return head_a;
  }

  ListNode* head = (head_a->val < head_b->val) ? head_a : head_b;
  ListNode* other = (head == head_a) ? head_b : head_a;

  ListNode* current = head->next;
  ListNode* previous = head;

  while(current && other)
  {
    if (other->val < current->val)
    {
      ListNode* other_next = other->next;

      previous->next = other;
      other->next = current;
      other = other_next;
      previous = previous->next;
    }
    else
    {
      previous = current;
      current = current->next;
    }
  }

  // link in any leftover nodes
  if (!current && other)
  {
    previous->next = other;
  }
  else if (!other && current)
  {
    previous->next = current;
  }

  return head;
}

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " <list A values> : <list B values" << std::endl;
    return 1;
  }

  ListNode* head_a = new ListNode(std::atoi(argv[1]));
  int i = 2;

  // build list A
  ListNode* p = head_a;
  while(i < argc && argv[i][0] != ':')
  {
    int val = std::atoi(argv[i]);

    ListNode* c = new ListNode(val);
    p->next = c;
    p = c;

    i++;
  }

  i++;

  ListNode* head_b = nullptr;

  if (i < argc)
  {
    head_b = new ListNode(std::atoi(argv[i]));
  }

  i++;

  // build list B
  p = head_b;
  while(i < argc && argv[i][0] != ':')
  {
    int val = std::atoi(argv[i]);

    ListNode* c = new ListNode(val);
    p->next = c;
    p = c;

    i++;
  }

  std::cout << "list A: ";
  print_list(head_a);

  std::cout << "list B: ";
  print_list(head_b);

  ListNode* merged_head = merge_lists(head_a, head_b);

  print_list(merged_head);

  return 0;
}
