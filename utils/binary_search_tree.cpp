#include "binary_search_tree.h"

#include <iostream>
#include <sstream>

namespace utils {

uint32_t log_base_2(const uint32_t value)
{
  uint32_t temp = value;
  uint32_t division_count = 0;

  while (temp > 0)
  {
    temp = temp >> 1;
    division_count++;
  }

  return division_count - 1;
}

BinarySearchTree::BinarySearchTree(const uint32_t initial_num_elements) :
  _item_count(0)
{
  _array_size = (2 << utils::log_base_2(initial_num_elements)) + 1;
  _array = new Node[_array_size];
}

BinarySearchTree::~BinarySearchTree()
{
  delete[] _array;
}

uint32_t BinarySearchTree::TreeHeight() const
{
  return Height(0);
}

void BinarySearchTree::Insert(const uint32_t value)
{
  uint32_t index = 0;

  while (index < _array_size)
  {
    if (_array[index].is_empty)
    {
      _array[index].value = value;
      _array[index].is_empty = false;

      _item_count++;

      if (index != 0)
      {
        Rebalance(ParentIndex(index));
      }

      break;
    }
    else if (value <= _array[index].value)
    {
      index = LeftChildIndex(index);
    }
    else if (value > _array[index].value)
    {
      index = RightChildIndex(index);
    }
  }

  if (index >= _array_size)
  {
    Resize();

    _array[index].value = value;
    _array[index].is_empty = false;

    _item_count++;

    Rebalance(ParentIndex(index));
  }
}

void BinarySearchTree::Remove(const uint32_t value)
{
}

std::string BinarySearchTree::ToString() const
{
  std::stringstream ss;

  for (uint32_t i = 0; i < _array_size; ++i)
  {
    if (_array[i].is_empty)
    {
      ss << "X ";
    }
    else
    {
      ss << _array[i].value << " ";
    }
  }

  return ss.str();
}

void BinarySearchTree::Rebalance(const uint32_t index)
{
  _array[index].balance = Height(RightChildIndex(index)) -
                          Height(LeftChildIndex(index));

  if (_array[index].balance == -2)
  {
  }
  else if (_array[index].balance == 2)
  {
  }

  if (index != 0)
  {
    Rebalance(ParentIndex(index));
  }
}

void BinarySearchTree::Resize()
{
  uint32_t new_size = _array_size * 2;
  Node* new_array = new Node[new_size];

  // copy contents of current array into the new array
  std::memcpy(new_array, _array, _array_size * sizeof(Node));

  delete[] _array;

  _array = new_array;
  _array_size = new_size;
}

uint32_t BinarySearchTree::Height(const uint32_t index) const
{
  if (index >= _item_count || _array[index].is_empty)
  {
    return 0;
  }

  uint32_t leftHeight = Height(LeftChildIndex(index));
  uint32_t rightHeight = Height(RightChildIndex(index));

  if (leftHeight > rightHeight)
  {
    return leftHeight + 1;
  }
  else
  {
    return rightHeight + 1;
  }
}

}
