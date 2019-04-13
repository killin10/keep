/*
 * @file auto_ptr_test.cc
 * @brief test our version auto_ptr
 *
 * @version 1.0
 * @date Mon Dec 10 21:25:30 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <iostream>

//#include <memory>

#include "auto_ptr.h"

//using std::auto_ptr;

void
Print(const auto_ptr<int> &p)
{
    *p = 2;

    std::cout << *p << std::endl;
}

int
main(int argc, char *argv[])
{
    //const auto_ptr<int> pv0(new int());
    //auto_ptr<int> pv0(new int());
    //auto_ptr<int> pv1(new int());
    //auto_ptr<int> pv1(pv0);
    //

    // compile error if no auto_ptr_ref
    auto_ptr<int> pv2 = auto_ptr<int>(new int());

    //pv0 = pv1;


    //auto_ptr<int> val(new int());

    //*val = 1;

    //Print(val);

    return 0;
}

