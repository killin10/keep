/**
 * smart pointer: shared_ptr
 *
 * @date Tue Nov  7 10:41:29 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <iostream>
#include <memory>

class D;
void f1(std::shared_ptr<D> p);
void f2(std::shared_ptr<D> p);

class D {
	public:
		D() {
			std::cout << "in D()" << std::endl;
		}

		D(int i): i_(i) {
			std::cout << "in D(int)" << std::endl;
		}

		~D() {
			std::cout << "in ~D()" << std::endl;
		}

		int i() {
			return i_;
		}

	private:
		int i_ = 1;
};

void f1(std::shared_ptr<D> p) {
	std::cout << "f1() " << p->i() << std::endl;
	f2(p);
}

void f2(std::shared_ptr<D> p) {
	std::cout << "f2() " << p->i() << std::endl;
}

void f3() {
	// use shared_ptr to mamange raw pointer
	D *p = new D();
	std::shared_ptr<D> sp(p);

	// do biz things & p will be deleted after return
}

int main(void) {
	f1(std::make_shared<D>(2));

	f3();

	std::cout << "before exit" << std::endl;
	return 0;
}
