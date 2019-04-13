/**
 * cpp11: move
 *
 * @date Fri Nov 10 11:06:27 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct C {
  C() { std::cout << "ctor" << std::endl; }

  ~C() { std::cout << "dtor" << std::endl; }

  C(const C &c) { std::cout << "copy ctor" << std::endl; }

  C &operator=(const C &c) {
    std::cout << "operator=" << std::endl;
    return *this;
  }

  C(C &&c) { std::cout << "move ctor" << std::endl; }
};

int main(void) {
  C c;
  C d = c;
  C e = std::move(c);

  std::vector<std::string> orignal{"one", "two", "three"};
  std::vector<std::string> dest(std::make_move_iterator(orignal.begin()),
                                std::make_move_iterator(orignal.end()));

  std::for_each(orignal.begin(), orignal.end(),
                [](const std::string &s) { std::cout << s << "\t"; });
  std::cout << std::endl;
  std::for_each(dest.begin(), dest.end(),
                [](const std::string &s) { std::cout << s << "\t"; });
  std::cout << std::endl;

  return 0;
}
