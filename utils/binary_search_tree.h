#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <string>

namespace utils {

uint32_t log_base_2(const uint32_t value);

class BinarySearchTree
{
public:
  BinarySearchTree(const uint32_t initial_num_elements);
  virtual ~BinarySearchTree();

  uint32_t TreeHeight() const;

  void Insert(const uint32_t value);
  void Remove(const uint32_t value);

  std::string ToString() const;

private:
  struct Node
  {
    Node() :
      is_empty(true),
      balance(0),
      value(0)
    {
    }

    bool is_empty;
    int8_t balance;
    uint32_t value;
  };

  uint32_t _array_size;
  uint32_t _item_count;

  Node* _array;

  void Rebalance(const uint32_t index);
  void Resize();
  uint32_t Height(const uint32_t index) const;

  void MoveSubTree(const uint32_t source, const uint32_t dest);

  void RotateLeft(const uint32_t source, const uint32_t dest);
  void RotateRight(const uint32_t source, const uint32_t dest);

  static inline uint32_t LeftChildIndex(const uint32_t index)
  {
    return index * 2 + 1;
  }

  static inline uint32_t RightChildIndex(const uint32_t index)
  {
    return index * 2 + 2;
  }

  static inline uint32_t ParentIndex(const uint32_t index)
  {
    return (index - 1) / 2;
  }
};

}

#endif
