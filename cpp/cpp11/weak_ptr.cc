/**
 * cpp11: weak_ptr
 *
 * @date Thu Nov  9 10:15:36 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <memory>

struct D {
  D() { std::cout << "D()" << std::endl; }

  ~D() { std::cout << "~D()" << std::endl; }
};

void f1(std::shared_ptr<D> p) { std::cout << "f1()" << std::endl; }

void f2(std::shared_ptr<D> p) {
  std::cout << "f2()" << std::endl;
  f1(p);
}

int main(void) {
  std::weak_ptr<D> wp;

  {
    std::shared_ptr<D> p = std::make_shared<D>();
    wp = p;
    std::cout << "use count(before): " << wp.use_count() << std::endl;
    f2(p);
  }

  std::cout << "use count(after): " << wp.use_count() << std::endl;
}
