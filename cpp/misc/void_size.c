//
// @file void_size.c
// @brief sizeof(void)
// 
// @version 1.0 
// @date Thu Oct 17 19:29:27 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <stdio.h>

int main(int argc, char* argv[]) {
  printf("sizeof(void): %lu\n", sizeof(void));
  printf("sizeof(function): %lu\n", sizeof(main));
  return 0;
}

