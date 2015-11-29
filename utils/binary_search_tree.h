template <typename T>
class BinarySearchTree
{
public:
  BinarySearchTree(const uint32_t height) :
    _height(height)
  {
    _array = new Node[(2 << height) - 1];
  }

  virtual ~BinarySearchTree()
  {
  }

  void Insert(const T& item)
  {
  }

  void Remove(const T& item)
  {
  }

private:
  struct Node
  {
    Node() :
      left(nullptr),
      right(nullptr)
    {
    }

    Node* left;
    Node* right;
    T value;
  };

  T* _array;
  uint32_t _height;
};
