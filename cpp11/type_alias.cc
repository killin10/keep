/**
 * type alias by using(the same as typedef)
 *
 * @date Wed Nov  1 22:36:47 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>

typedef double dt;

int main(int argc, char *argv[]) {
	using dtt = double;

	dt d1 = 1.1;
	dtt d2 = 2.1;

	std::cout << d1 << std::endl
		<< d2 << std::endl;
	return 0;
}
