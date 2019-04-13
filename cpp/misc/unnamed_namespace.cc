/*
 * @file unnamed_namespace.cc
 * @brief using unnamed namespace in .cc file
 *
 * @version 1.0
 * @date Tue Nov 20 11:32:23 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <iostream>

namespace
{

void
FuncInUnnamedNS()
{
    std::cout << "func in unnamed namespace" << std::endl;
}

}  // namespace


int 
main(int argc, char *argv[])
{
    FuncInUnnamedNS();

    return 0;
}

