/**
 * cpp11: final
 *
 * @date Wed Nov 15 22:51:35 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */
#include <iostream>

class X final {};

// compile error
// class D : public X {};

class X1 {
 public:
  virtual ~X1() {}

  void f1() {}
  virtual void f2() {}
};

class D1 : public X1 {
 public:
  void f1() { std::cout << "D1::f1()" << std::endl; }

  void f2() final {}
};

class D2 : public D1 {
 public:
  void f1() {}
  // compile error
  // void f2() {}
};

int main() { return 0; }
