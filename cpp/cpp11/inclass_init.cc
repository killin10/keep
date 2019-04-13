/**
 * in-class initializer
 *
 * @date Wed Nov  1 23:42:10 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <string>
#include <iostream>

struct SalesDate {
	std::string bookNo;
	unsigned unitsSold = 0;
	double revenue{1.2};
};

int main(void) {
	struct SalesDate s;
	std::cout << s.unitsSold << std::endl
		<< s.revenue << std::endl;

	return 0;
}
