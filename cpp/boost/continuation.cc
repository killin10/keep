/**
 * Boost.Context
 *
 * @date Wed Nov  8 20:21:29 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>

#include <boost/context/continuation.hpp>

namespace ctx = boost::context;

/**
 * using continuation directly
 */
void f1() {
  int i;

  ctx::continuation source = ctx::callcc([&](ctx::continuation&& sink) {
    std::cout << "source context 1st" << std::endl;
    i = 0;
    sink = sink.resume();
    std::cout << "source context 2nd" << std::endl;
    i += 1;
    sink = sink.resume();
    std::cout << "source context 3rd" << std::endl;
		i += 1;
		sink = sink.resume();
		std::cout << "source context end" << std::endl;
    return std::move(sink);
  });

  std::cout << "main context 1st: " << i << std::endl;
  source = source.resume();
  std::cout << "main context 2nd: " << i << std::endl;
  source = source.resume();
	std::cout << "main context 3rd: " << i << std::endl;
	source = source.resume();
	std::cout << "main context end" << std::endl;
}

/**
 * using high level execution_context
 */
void f2() {
	//ctx::execution_context<int> fctx;
}

int main(void) {
  f1();

  return 0;
}
