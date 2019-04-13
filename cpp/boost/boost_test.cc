/**
 * Boost.Test
 *
 * @date Mon Nov  6 14:55:31 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

// must defined before includes
#define BOOST_TEST_MODULE Boost Test Demo

// header-only usage variant
//#include <boost/test/included/unit_test.hpp>
// use dynamic link
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <boost/mpl/list.hpp>

namespace utf = boost::unit_test;
namespace bdata = boost::unit_test::data;

struct FC {
  FC() : i( 0 ) {
		BOOST_TEST_MESSAGE( "case setup fixture" );
	}
  ~FC() {
		BOOST_TEST_MESSAGE( "case teardown fixture" );
	}

  int i;
};

struct FS {
	FS() {
		BOOST_TEST_MESSAGE("suite setup entry/exit fixture");
	}
	~FS() {
		BOOST_TEST_MESSAGE("suite teardown entry/exit fixture");
	}
};

struct FG {
	FG() {
		BOOST_TEST_MESSAGE("global ctor fixture");
	}
	~FG() {
		BOOST_TEST_MESSAGE("global dtor fixture");
	}

	void setup() {
		BOOST_TEST_MESSAGE("global setup fixture");
	}

	void teardown() {
		BOOST_TEST_MESSAGE("global teardown fixture");
	}
};

BOOST_TEST_GLOBAL_FIXTURE(FG);

BOOST_FIXTURE_TEST_SUITE(test_suite_1, FC)

	BOOST_TEST_DECORATOR(*utf::description("with description")
			*utf::label("label_1"))
	BOOST_AUTO_TEST_CASE(first_test,
			*utf::depends_on("test_suite_1/first_test_2")) {
		BOOST_TEST_MESSAGE("test_suite_1/first_test_1");
		int i = 1;
		BOOST_TEST(i);
		BOOST_TEST(i == 2);
	}

	BOOST_AUTO_TEST_CASE(first_test_2) {
		BOOST_TEST_MESSAGE("test_suite_1/first_test_2");
		int i = 1;
		BOOST_TEST(i);
	}

	BOOST_AUTO_TEST_CASE(first_test_3, *utf::disabled()) {
		int i = 1;
		BOOST_TEST(i);
	}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_suite_2, *utf::fixture<FS>())

	BOOST_DATA_TEST_CASE(equal_test,
			bdata::make({1, 2, 3}) ^ bdata::make({2, 2, 3}), sample, exp) {
		BOOST_TEST(sample == exp);
	}

	typedef boost::mpl::list<int, long, unsigned char> test_types;
	BOOST_AUTO_TEST_CASE_TEMPLATE(my_test, T, test_types) {
		BOOST_TEST_CONTEXT("It's Scoped Context") {
			BOOST_TEST(sizeof(T) == (unsigned) 4);
		}
	}

BOOST_AUTO_TEST_SUITE_END()
