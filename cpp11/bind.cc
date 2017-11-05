/**
 * bind arguments for functions
 *
 * @date Mon Nov  6 01:23:41 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <functional>

using std::placeholders::_1;
using std::placeholders::_2;

void print(std::ostream &out, int a, int b , int c) {
	std::cout << a << "\t" << b << "\t" << c << std::endl;
}

int main(void) {
	auto f1 = std::bind(print, ref(std::cout), _2, _1, 3);
	f1(1, 2);

	return 0;
}
