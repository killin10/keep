/**
 * use lambda
 *
 * @date Mon Nov  6 01:06:47 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>

int main(void) {
	int a = 1;
	int b = 2;
	int c = 3;

	auto l1 = [a, b] (const int &i) -> int {
		return a + b + i;
	};

	auto l2 = [] () {
		return 10;
	};

	auto l3 = [=] () {
		return a + b;
	};

	auto l4 = [&] () -> int {
		a = 5;
		return a + b;
	};

	auto l5 = [=, &b] ()-> int {
		b = 6;
		return a + b;
	};

	std::cout << l1(c) << std::endl
		<< l2() << std::endl
		<< l3() << std::endl
		<< l4() << std::endl
		<< "a = " << a << std::endl
		<< l5() << std::endl
		<< "b = " << b << std::endl;

	return 0;
}
