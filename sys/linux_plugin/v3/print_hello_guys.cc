/*
 * @file print_hello_guys.cc
 * @brief Print "Hello, guys!" to stdout.
 * 
 * @version 1.0 
 * @date Wed Jan  9 22:07:00 2013
 * 
 * @copyright Copyright (C) 2013 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <stdio.h>

#include "plugin.h"

const int kGuysId = 1;
const char* kGuysDesc = "Print \"Hello, guys!\"";

int Id()
{
    return kGuysId;
}

const char* Desc()
{
    return kGuysDesc;
}

