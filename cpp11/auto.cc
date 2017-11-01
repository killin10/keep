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

	auto a = r;
	auto b = ci;
	b = 3;
	auto c = &ci;
	auto &d = ci;
	const auto &e = 42;

	return 0;
}
