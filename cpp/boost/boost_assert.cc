/**
 * use Boost.Assert
 *
 * @date Sat Nov  4 00:53:17 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#define BOOST_ENABLE_ASSERT_HANDLER

#include <iostream>
#include <string>

#include <boost/assert.hpp>

namespace boost
{
	void assertion_failed_msg(char const *expr, char const *msg,
			const char *function,
			char const *file, long line) {
		std::cerr << "BOOST_ASSERT FAIL: " << expr
			<< ", function '" << function
			<< "' at file " << file << ":" << line
			<< ", " << msg
			<< std::endl;
	}
}

int main(void) {
	// BOOST_ASSERT
	// default expand to assert(expr)

	BOOST_ASSERT_MSG(false, "intentionally failure");

	return 0;
}
