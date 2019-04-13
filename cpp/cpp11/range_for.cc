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

	int arr[3][4] = {
		{1, 2, 3, 4},
		{21, 22, 23, 24},
		{31, 32, 33, 34}
	};
	for (auto &row : arr) {
		for (auto e : row) {
			std::cout << e << "\t";
		}
		std::cout << std::endl;
	}

	return 0;
}
