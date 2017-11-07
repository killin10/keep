/**
 * Boost.Stacktrace
 * @date Tue Nov  7 16:50:24 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>

//#define BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED
#define BOOST_STACKTRACE_DYN_LINK
#include <boost/stacktrace.hpp>

void f1() {
	std::cout << boost::stacktrace::stacktrace();
}

void f2() {
	f1();
}

void f3() {
	f2();
}

int main(void) {
	f3();
	return 0;
}
