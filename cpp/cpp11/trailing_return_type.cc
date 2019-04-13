/**
 * trailing return type for complex function declaration
 *
 * @date Fri Nov  3 00:47:09 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <string>

constexpr int ARR_SIZE = 3;

auto trans(std::initializer_list<std::string> args) -> std::string (*)[ARR_SIZE] {
	using strArr = std::string[ARR_SIZE];
	strArr *p = new std::string[1][ARR_SIZE];

	std::string *i = begin(*p);
	for (auto s : args) {
		*i++ = s;
	}

	return p;
}

int main(void) {
	std::string (*strArrP)[ARR_SIZE] = trans({"hello", "world", "haha"});

	for (auto s : *strArrP) {
		std::cout << s << std::endl;
	}

	delete []strArrP;
	return 0;
}
