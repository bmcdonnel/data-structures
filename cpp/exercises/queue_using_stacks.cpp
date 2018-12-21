#include <iostream>
#include <stack>

template<typename T>
class Queue
{
public:
  Queue() {}
  virtual ~Queue() {}

  void push(T val)
  {
    while(!_pop.empty())
    {
      _push.push(_pop.top());
      _pop.pop();
    }

    _push.push(val);
  }

  void pop()
  {
    while(!_push.empty())
    {
      _pop.push(_push.top());
      _push.pop();
    }

    _pop.pop();
  }

  T peek()
  {
    while(!_push.empty())
    {
      _pop.push(_push.top());
      _push.pop();
    }

    return _pop.top();
  }

  bool empty()
  {
    while(!_push.empty())
    {
      _pop.push(_push.top());
      _push.pop();
    }

    return _pop.empty();
  }

private:
  std::stack<T> _push;
  std::stack<T> _pop;
};

int main(int argc, char** argv)
{
  Queue<int> queue;

  for (int i = 0; i < 10; ++i)
  {
    std::cout << "push " << i << std::endl;
    queue.push(i);
  }

  for (int i = 0; i < 5; ++i)
  {
    std::cout << "pop " << queue.peek() << std::endl;
    queue.pop();
  }

  queue.push(9999);

  std::cout << "pop " << queue.peek() << std::endl;
  queue.pop();

  for (int i = 0; i < 5; ++i)
  {
    std::cout << "pop " << queue.peek() << std::endl;
    queue.pop();
  }

  if (queue.empty())
  {
    std::cout << "queue is empty" << std::endl;
  }
  else
  {
    std::cout << "queue is NOT empty" << std::endl;
  }

  return 0;
}
