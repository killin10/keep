/**
 * cpp11: unique_ptr
 *
 * @date Wed Nov  8 10:20:17 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <memory>

class C
{
	public:
		C() {
			std::cout << "C()" << std::endl;
		}

		~C() {
			std::cout << "~C()" << std::endl;
		}
};

void f1(std::unique_ptr<C> p) {
	std::cout << "f1()" << std::endl;
}

void f2(std::unique_ptr<C> p) {
	std::cout << "f2()" << std::endl;
	f1(std::move(p));
}

void f3() {
	// for dynamic array
	std::unique_ptr<C[]> p(new C[3]);
}

int main(void) {
	std::unique_ptr<C> cp(new C());

	f2(std::move(cp));

	std::cout << "nullptr in cp? "
		<< (cp.get() == nullptr ? "true" : "false")
		<< std::endl;

	f3();
}
