/**
 * cpp11: override
 *
 * @date Wed Nov 15 22:58:57 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>

class X {
 public:
  virtual void f1() {}
  void f2() {}
};

class D : public X {
 public:
  void f1() override { std::cout << "D::f1()" << std::endl; }

  // compile error
  // void f2() override {}
};

int main() { return 0; }
