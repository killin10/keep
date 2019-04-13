/**
 * make compiler generate the default constructor
 *
 * @date Sat Nov  4 02:20:29 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <string>
#include <iostream>

struct SalesData {
	SalesData() = default;
	SalesData(const std::string &s, const int &p) :
		bookNo(s), price(p) {}

	std::string bookNo;
	int price = 3;
};

int main(void) {
	SalesData sd1;
	SalesData sd2("my bookNo", 5);

	std::cout << "SD1: " << sd1.bookNo << ", " << sd1.price << std::endl
		<< "SD2: " << sd2.bookNo << ", " << sd2.price << std::endl;

	return 0;
}

