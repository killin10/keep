/**
 * sizeof on class member
 *
 * @date Thu Nov  2 23:51:45 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>

struct SalesData {
	int a;
};

int main(void) {
	std::cout << sizeof SalesData::a << std::endl;
	return 0;
}
