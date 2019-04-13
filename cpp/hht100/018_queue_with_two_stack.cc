//
// @file 018_queue_with_two_stack.cc
// @brief Implement a queue with two stacks.
// 
// @version 1.0 
// @date Mon Jun 17 19:20:24 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <stack>

#include <assert.h>

template <typename T>
class Queue {
 public:
  Queue() {}
  ~Queue() {}

  void push(const T& val);
  void pop();
  const T& front();

 private:
  std::stack<T> stack1_;  // normal stack
  std::stack<T> stack2_;  // reverse stack
};

template <typename T>
void Queue<T>::push(const T& val) {
  stack1_.push(val);
}

template <typename T>
void Queue<T>::pop() {
  if (!stack2_.empty()) {
    stack2_.pop();
  } else {
    while (!stack1_.empty()) {
      stack2_.push(stack1_.top());
      stack1_.pop();
    }
    assert(!stack2_.empty());
    stack2_.pop();
  }
}

template <typename T>
const T& Queue<T>::front(){
  if (!stack2_.empty()) {
    return stack2_.top();
  } else {
    while (!stack1_.empty()) {
      stack2_.push(stack1_.top());
      stack1_.pop();
    }
    assert(!stack2_.empty());
    return stack2_.top();
  }
}

template <typename T>
void ShowAndDeleteHead(Queue<T>* queue) {
  std::cout << queue->front() << std::endl;
  queue->pop();
}

int main(int argc, char* argv[]) {
  Queue<int> queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  ShowAndDeleteHead(&queue);
  ShowAndDeleteHead(&queue);
  queue.push(4);
  ShowAndDeleteHead(&queue);
  ShowAndDeleteHead(&queue);
  return 0;
}

