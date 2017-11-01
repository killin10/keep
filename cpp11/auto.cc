/**
 * auto type
 *
 * @date Wed Nov  1 22:53:43 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>

int main(void) {
	int i = 0, &r = i;
	const int ci = i, &cr = ci;

	// a is int
	auto a = r;
	// b is int
	auto b = ci;
	b = 3;
	// c is const int *
	auto c = &ci;
	// d is const ref
	auto &d = ci;
	// e is const ref
	const auto &e = 42;

	return 0;
}
