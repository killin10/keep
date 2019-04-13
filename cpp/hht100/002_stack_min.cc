//
// @file stack_min.cc
// @brief Add a min operation to stack implementation, 
//   push, pop and min will all finish in O(1) time.
// 
// @version 1.0
// @date Wed May 29 23:47:37 2013
// 
// @copyright Copyright (C) 2013
// @author shiwei<shiwei2012@gmail.com>
//

#include <deque>
#include <iostream>

#include <assert.h>

template <typename T>
class MinStack {
 public:
  MinStack() {};
  ~MinStack() {};

  T& Top();
  const T& Top() const;

  void Push(const T& value);
  void Pop();

  const T& Min() const;

 private:
  std::deque<T> data_;
  std::deque<size_t> min_;
};

template <typename T>
inline T& MinStack<T>::Top() {
  return data_.back();
}

template <typename T>
inline const T& MinStack<T>::Top() const {
  return data_.back();
}

template <typename T>
void MinStack<T>::Push(const T& value) {
  data_.push_back(value);

  if (min_.size() == 0) {
    min_.push_back(0);
  } else {
    if (value < data_[min_.back()]) {
      min_.push_back(data_.size() - 1);
    } else {
      min_.push_back(min_.back());
    }
  }
}

template <typename T>
inline void MinStack<T>::Pop() {
  data_.pop_back();
  min_.pop_back();
}

template <typename T>
inline const T& MinStack<T>::Min() const {
  assert(data_.size() > 0);
  assert(min_.size() > 0);
  return data_[min_.back()];
}

int main(int argc, char* argv[]) {
  MinStack<int> ms;
  ms.Push(3);
  ms.Push(2);
  ms.Push(4);
  ms.Push(7);
  ms.Push(1);
  ms.Push(3);

  for (int i = 0; i < 6; ++i) {
    std::cout << "current min: " << ms.Min() << std::endl;
    ms.Pop();
  }

  return 0;
}


