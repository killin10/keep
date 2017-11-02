/**
 * initializer_list type to define varargs function
 *
 * @date Fri Nov  3 00:33:49 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <string>

void print(std::initializer_list<std::string> args) {
	for (auto s : args) {
		std::cout << s << std::endl;
	}
}

int main(void) {
	print({"hello", "world", "haha"});
	return 0;
}
