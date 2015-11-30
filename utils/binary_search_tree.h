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
}

template <typename T>
class BinarySearchTree
{
public:
  BinarySearchTree(const uint32_t initial_num_elements) :
    _item_count(0)
  {
    _array_size = (2 << utils::log_base_2(initial_num_elements)) + 1;
    _array = new Node[_array_size];
  }

  virtual ~BinarySearchTree()
  {
    delete[] _array;
  }

  uint32_t TreeHeight() const
  {
    return Height(0);
  }

  void Insert(const T& value)
  {
    uint32_t index = 0;

    while (index < _array_size)
    {
      if (_array[index].is_empty)
      {
        _array[index].value = value;
        _array[index].is_empty = false;

        _item_count++;

        Rebalance(ParentIndex(index));
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
  }

  void Remove(const T& value)
  {
  }

  std::string ToString() const
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

private:
  struct Node
  {
    Node() :
      is_empty(true)
    {
    }

    bool is_empty;
    uint8_t balance;
    T value;
  };

  uint32_t _array_size;
  uint32_t _item_count;

  Node* _array;

  void Rebalance(const uint32_t index)
  {
    _array[index].balance = Height(RightChildIndex(index)) - Height(LeftChildIndex(index));

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

  uint32_t Height(const uint32_t index) const
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

  static uint32_t LeftChildIndex(const uint32_t index)
  {
    return index * 2 + 1;
  }

  static uint32_t RightChildIndex(const uint32_t index)
  {
    return index * 2 + 2;
  }

  static uint32_t ParentIndex(const uint32_t index)
  {
    return (index - 1) / 2;
  }
};
