/**
 * constexpr function
 *
 * @date Fri Nov  3 01:15:32 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <cstddef>

constexpr int new_sz() {
	return 42;
}

constexpr int scale(const size_t cnt) {
	return new_sz() * cnt;
}

int main(void) {
	constexpr int arr[scale(2)] = {0};
	int i = 1;
	// compile error
	//constexpr int arr2[scale(i)] = {0};

	return 0;
}
