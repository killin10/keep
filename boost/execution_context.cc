/**
 * Boost.Context::execution_context
 *
 * @date Wed Nov  8 22:33:39 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>

#include <boost/context/execution_context.hpp>

void f() {
  namespace ctx = boost::context;

  ctx::execution_context<int> fctx(
      [&](ctx::execution_context<int>&& sink, int i) {
        std::cout << "sub ctx entered" << std::endl;
        int start = i;
        for (;;) {
          auto result = sink(start);
          sink = std::move(std::get<0>(result));
          ++start;
        }
        return std::move(sink);
      });

  std::cout << "main ctx continued" << std::endl;
  for (int i = 5; i < 10; ++i) {
    auto result = fctx(i);
    fctx = std::move(std::get<0>(result));
    std::cout << std::get<1>(result) << std::endl;
  }
}

int main(void) {
  f();
  return 0;
}
