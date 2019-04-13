/**
 * fist boost program
 *
 * @date Fri Nov  3 22:05:01 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <iterator>
#include <algorithm>

#include <boost/lambda/lambda.hpp>

int main(void) {
	using namespace boost::lambda;
	using in = std::istream_iterator<int>;

	std::for_each(in(std::cin), in(), std::cout << (_1 * 3) << " ");

	return 0;
}
