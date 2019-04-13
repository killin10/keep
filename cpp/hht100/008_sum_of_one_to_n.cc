//
// @file 008_sum_of_one_to_n.cc
// @brief Accumulate from 1 to n without if, switch, for, while etc.
//   And no multiplication and division.
// 
// @version 1.0 
// @date Sun Jun  9 23:05:57 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

// Solution 1: constructor

class Accumulator {
 public:
  Accumulator() {
    sum_ += ++n_;
  }

  static void Reset() {
    n_ = 0;
    sum_ = 0;
  }

  static int sum() {
    return sum_;
  }

 private:
  static int n_;
  static int sum_;
};

int Accumulator::n_ = 0;
int Accumulator::sum_ = 0;

void Solution1(int n) {
  Accumulator::Reset();
  Accumulator* tmp_array = new Accumulator[n];
  delete []tmp_array;
  std::cout << "Solution1: " << Accumulator::sum() << std::endl;
}

// Solution 2: recursion

typedef int (*RecFunc)(int);

// Terminating condition
int Terminate(int n) {
  return 0;
}

// Recursion
int Accumulate(int n) {
  RecFunc funcs[] = {Terminate, Accumulate};
  return n + funcs[!!n](n - 1);
}

void Solution2(int n) {
  std::cout << "Solution2: " << Accumulate(n) << std::endl;
}

// Solution 3: compiler

template <int n> struct TemplateAccumulator {
  enum Value {
    kN = TemplateAccumulator<n - 1>::kN + n
  };
};

template <> struct TemplateAccumulator<1> {
  enum Value {
    kN = 1
  };
};

void Solution3() {
  std::cout << "Solution3: " << TemplateAccumulator<10>::kN << std::endl;
}

// test

int main(int argc, char* argv[]) {
  int n = 10;
  Solution1(n);
  Solution2(n);
  Solution3();

  return 0;
}

