/**
 * begin() & end() lib function for array
 *
 * @date Thu Nov  2 00:43:10 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};
	int *b = std::begin(arr), *e = std::end(arr);

	for (; b < e; ++b) {
		std::cout << *b;
	}
	std::cout << std::endl;

	for (auto i : arr) {
		std::cout << i;
	}
	std::cout << std::endl;

	return 0;
}
