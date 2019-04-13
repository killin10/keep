/*
 * @file print_hello_world.cc
 * @brief Print "Hello, world!" to stdout.
 *
 * @version 1.0
 * @date Wed Oct 31 19:35:36 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <stdio.h>

#include "plugin.h"

const int kWorldId = 2;
const char* kWorldDesc = "Print \"Hello, world!\"";

int Id()
{
    return kWorldId;
}

const char* Desc()
{
    return kWorldDesc;
}

