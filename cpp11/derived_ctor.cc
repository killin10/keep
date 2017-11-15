/**
 * cpp11: derive ctor from base class
 *
 * @date Wed Nov 15 23:03:20 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <sstream>
#include <string>

class X {
 public:
  X(const int &i, const std::string &s) : i_(i), s_(s) {
    std::cout << "X::X(int, string)" << std::endl;
  }

  const int &i() const { return i_; }

  const std::string &s() const { return s_; }

 private:
  int i_;
  std::string s_;
};

class D : public X {
 public:
  using X::X;

  D(const int &i, const std::string &s, const std::string &t) : X(i, s), t_(t) {
    std::cout << "D::D(int, string, string)" << std::endl;
  }

  std::string ToString() const {
    std::stringstream ss;
    ss << "i_ = " << i() << ", "
       << "s_ = " << s() << ", "
       << "t_ = " << t_;
    return ss.str();
  }

 private:
  std::string t_;
};

int main() {
  D d(1, "sss");
  D d1(2, "sss", "ttt");

  std::cout << d.ToString() << std::endl;
  std::cout << d1.ToString() << std::endl;

  return 0;
}
