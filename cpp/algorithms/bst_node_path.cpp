#include <iostream>
#include <cstdint>
#include <set>

#include "utils/binary_search_tree.h"

int main(int argc, char** argv)
{
  if (argc < 5)
  {
    std::cout << "usage: " << argv[0] << " (value A) (value B) <list of values>" << std::endl;
    return 1;
  }

  const int32_t valueA = std::atoi(argv[1]);
  const int32_t valueB = std::atoi(argv[2]);

  const uint32_t size = argc - 3;

  utils::BinarySearchTree bst(size);

  for (uint32_t i = 0; i < size; ++i)
  {
    bst.Insert(std::atoi(argv[i + 3]));
  }

  std::cout << bst.ToString() << std::endl;

  std::cout << "tree height: " << bst.TreeHeight() << std::endl;

  std::cout << "finding path between values " << valueA << " and " << valueB << std::endl;

  std::set<int32_t> seen;
  int32_t parentValueA;
  int32_t parentValueB;

  // TODO(bryan) implement this such that an O(nlog(n)) search isn't needed each time
  //   - option 1: expose array-based storage mechanism
  //   - option 2: add redundant pointers to Node struct and expose the struct
  bool hasParentA = bst.GetParent(valueA, &parentValueA);
  bool hasParentB = bst.GetParent(valueB, &parentValueB);

  while (hasParentA && hasParentB)
  {
    seen.insert(parentValueA);

    if (seen.count(parentValueB) != 0)
    {
      // done
      break;
    }
    else
    {
      seen.insert(parentValueB);
    }

    hasParentA = bst.GetParent(parentValueA, &parentValueA);
    hasParentB = bst.GetParent(parentValueB, &parentValueB);
  }

  for (const int32_t value : seen)
  {
    std::cout << value << std::endl;
  }
}
