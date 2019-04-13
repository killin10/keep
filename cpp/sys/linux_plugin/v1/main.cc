/*
 * @file main.cc
 * @brief Plugin framework version 1
 *
 * @version 1.0
 * @date Wed Oct 31 19:34:50 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include <string>

#include <dlfcn.h>

#include "print.h"

const std::string kLibPath = "libprint.so";
const std::string kFuncName = "print";

int main(int argc, char* argv[])
{
    // open .so library file
    void* handle = NULL;
    handle = dlopen(kLibPath.c_str(), RTLD_LAZY);

    if (NULL == handle) {
        fprintf(stderr, "dlopen error, %s\n", dlerror());
        return 1;
    }

    // find function address in .so file
    typedef void (func_type)();

    func_type* print = NULL;
    print = (func_type*) dlsym(handle, kFuncName.c_str());

    if (NULL == print) {
        fprintf(stderr, "dlsym error, %s\n", dlerror());
        return 1;
    }

    // call that function
    print();

    // close .so file and release resource
    dlclose(handle);
    handle = NULL;

    return 0;
}

