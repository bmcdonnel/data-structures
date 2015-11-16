#ifndef LOCK_FREE_QUEUE_H_
#define LOCK_FREE_QUEUE_H_

#include <cstdint>
#include <atomic>

template <class T, int SIZE>
class LockFreeQueue
{
public:
  LockFreeQueue() : head_(0), tail_(0) {}

  bool TryPop(T& x)
  {
    if(!Empty())
    {
      x = queue_[head_++ % SIZE];
      return true;
    }

    return false;
  }

  bool TryPush(T& x)
  {
    if(!Full())
    {
      queue_[tail_++ % SIZE] = x;
      return true;
    }

    return false;
  }

  inline uint64_t Size() { return tail_ - head_; }
  inline bool Full() { return Size() == SIZE; }
  inline bool Empty() { return tail_ == head_; }

private:
  std::atomic<uint64_t> head_;
  std::atomic<uint64_t> tail_;

  T queue_[SIZE];
};


#endif
