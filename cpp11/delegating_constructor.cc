/**
 * delegating constructor
 *
 * @date Sun Nov  5 21:25:59 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <string>

class SalesData {
	public:
		SalesData(const std::string &book_no,
				const int &unit_price,
				const int &sales_no):
			book_no_(book_no), unit_price_(unit_price),
			sales_no_(sales_no) {
				std::cout << "SalesData_3 invoked" << std::endl;
			}

		// delegating to constructor with 3 args
		SalesData(): SalesData("", 0, 0) {}

	private:
		std::string book_no_;
		int unit_price_;
		int sales_no_;
};

int main(void) {
	SalesData sd;
	return 0;
}
