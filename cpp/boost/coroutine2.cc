/**
 * Boost.Coroutine2
 *
 * @date Tue Nov  7 21:52:57 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

#include <boost/coroutine2/all.hpp>

void f1() {
  typedef boost::coroutines2::coroutine<int> coro_t;

  coro_t::pull_type source([&](coro_t::push_type& sink) {
    int first = 1, second = 1;
    sink(first);
    sink(second);

    for (int i = 0; i < 8; ++i) {
      int third = first + second;
      first = second;
      second = third;
      sink(third);
    }
  });

  for (auto i : source) std::cout << i << " ";
  std::cout << std::endl;
}

void f2() {
  typedef boost::coroutines2::coroutine<std::string> coro_t;

  struct FinalEOL {
    ~FinalEOL() { std::cout << std::endl; }
  };

  const int num = 5, width = 15;
  coro_t::push_type writer([&](coro_t::pull_type& in) {
    // finish the last line when we leave by whatever means
    FinalEOL eol;
    // pull values from upstream, lay them out 'num' to a line
    for (;;) {
      for (int i = 0; i < num; ++i) {
        // when we exhaust the input, stop
        if (!in) return;
        std::cout << std::setw(width) << in.get();
        // now that we've handled this item, advance to next
        in();
      }
      // after 'num' items, line break
      std::cout << std::endl;
    }
  });

  std::vector<std::string> words{
      "peas",     "porridge", "hot", "peas", "porridge", "cold", "peas",
      "porridge", "in",       "the", "pot",  "nine",     "days", "old"};

  std::copy(begin(words), end(words), begin(writer));
}

int main(void) {
  f1();
	f2();

  return 0;
}
