/**
 * list initialization
 *
 * @date Wed Nov  1 21:44:35 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */
#include <iostream>

int main(int argc, char *argv[]) {
	int i = 1;
	int i2(2);
	// c++11
	int i3{3};
	int i4 = {4};

	long double ld = 3.1415926536;
	int c(ld), d = ld;
	// compile error because of information lost
	//int a{ld}, b = {ld};

	return 0;
}
