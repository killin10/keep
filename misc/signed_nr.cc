#include <iostream>

int main(int argc, char *argv[]) {
	unsigned u = 10, u2 = 42;
	std::cout << u - u2 << std::endl;

	int i = 10, i2 = 42;
	std::cout << i - u << std::endl;
	std::cout << u - i2 << std::endl;

	return 0;
}
