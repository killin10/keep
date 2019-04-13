//
// @file 018_01_stack_with_two_queue.cc
// @brief Implement a stack with two queues.
// 
// @version 1.0 
// @date Wed Jun 19 20:46:31 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <queue>

#include <assert.h>

template <typename T>
class Stack {
 public:
  Stack() {}
  ~Stack() {}

  void push(const T& val);
  void pop();
  const T& top();
 
 private:
  std::queue<T> queue1_;  // normal queue
  std::queue<T> queue2_;  // reverse queue
};

template <typename T>
void Stack<T>::push(const T& val) {
  assert(queue1_.empty() || queue2_.empty());
  if (!queue1_.empty()) {
    queue1_.push(val);
  } else {
    queue2_.push(val);
  }
}

template <typename T>
void Stack<T>::pop() {
  if (!queue1_.empty()) {
    assert(queue2_.empty());
    int queue_size = queue1_.size();
    for (int i = 0; i < queue_size - 1; ++i) {
      queue2_.push(queue1_.front());
      queue1_.pop();
    }
    queue1_.pop();
  } else if (!queue2_.empty()) {
    assert(queue1_.empty());
    int queue_size = queue2_.size();
    for (int i = 0; i < queue_size - 1; ++i) {
      queue1_.push(queue2_.front());
      queue2_.pop();
    }
    queue2_.pop();
  } else {
    // should never reach here
    assert(!(queue1_.empty() && queue2_.empty()));
  }
}

template <typename T>
const T& Stack<T>::top() {
  assert(!queue1_.empty() || !queue2_.empty());
  assert(queue1_.empty() || queue2_.empty());

  if (!queue1_.empty()) {
    return queue1_.back();
  }
  return queue2_.back();
}

template <typename T>
void ShowAndDeleteTop(Stack<T>* stack) {
  std::cout << stack->top() << std::endl;
  stack->pop();
}

int main(int argc, char* argv[]) {
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  ShowAndDeleteTop(&stack);
  ShowAndDeleteTop(&stack);
  stack.push(4);
  ShowAndDeleteTop(&stack);
  ShowAndDeleteTop(&stack);
  return 0;
}

