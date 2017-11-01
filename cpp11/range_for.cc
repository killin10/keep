/**
 * range for
 *
 * @date Thu Nov  2 00:04:17 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <string>
#include <cctype>

int main(void) {
	std::string s("hello world!");

	for (auto c : s) {
		std::cout << c;
	}
	std::cout << std::endl;

	for (auto &c : s) {
		c = std::toupper(c);
	}
	std::cout << s << std::endl;

	return 0;
}
