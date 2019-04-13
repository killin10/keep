/**
 * cpp11: explicit conversion operator
 *
 * @date Wed Nov 15 22:24:51 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <string>

class X {
 public:
  explicit operator std::string() const { return "string"; }

  operator int() const { return 1; }
};

int main(void) {
  X x;

  int i = x;

  // compile error
  // std::string b1 = x;
  std::string b2 = static_cast<std::string>(x);

  return 0;
}
