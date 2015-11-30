#include <sstream>

template <typename T>
class BinarySearchTree
{
public:
  BinarySearchTree(const uint32_t initial_num_elements) :
    _array_size(initial_num_elements),
    _item_count(0)
  {
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
    uint32_t i = 0;
    while (i < _array_size)
    {
      if (_array[i].is_empty)
      {
        _array[i].value = value;
        _array[i].is_empty = false;

        _item_count++;
        break;
      }
      else if (value <= _array[i].value)
      {
        i = (2 * i + 1);
      }
      else if (value > _array[i].value)
      {
        i = (2 * i + 2);
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
  }

  uint32_t Height(const uint32_t index) const
  {
    if (_array[index].is_empty)
    {
      return 0;
    }

    uint32_t leftHeight = Height(index * 2 + 1);
    uint32_t rightHeight = Height(index * 2 + 2);

    if (leftHeight > rightHeight)
    {
      return leftHeight + 1;
    }
    else
    {
      return rightHeight + 1;
    }
  }
};
