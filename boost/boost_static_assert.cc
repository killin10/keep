/**
 * demo of boost static assert
 *
 * @date Mon Nov  6 14:18:26 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <limits>

#include <boost/static_assert.hpp>

template<typename T>
class MyClass
{
	private:
		BOOST_STATIC_ASSERT_MSG(std::numeric_limits<T>::digits >= 16,
				"Template argument UnsignedInt must have at least 16 bits precision.");
};

int main(void) {
	MyClass<int> intCls;
	// compile error because of static assert
	//MyClass<short> shortClass;

	return 0;
}
