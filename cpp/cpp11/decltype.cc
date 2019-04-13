/**
 * decltype type specifier
 *
 * @date Wed Nov  1 23:24:21 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>

int f(void) {
	std::cout << "in f()" << std::endl;
	return 1;
}

int main(void) {
	// sum is int
	decltype(f()) sum = 1;

	const int ci = 2, &rci = 3;
	// a is const int
	decltype(ci) a = 1;
	// b is const int &
	decltype(rci) b = ci;

	int i = 42, *p = &i, &r = i;
	// c is int
	decltype(r + 0) c;
	// d is int &
	decltype(*p) d = i;
	// (i) is an expression, the type is int &
	decltype((i)) e = i;
	// f is int
	decltype(i) f;

	return 0;
}
