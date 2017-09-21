/**
 * to operate a const field using a union without type cast
 *
 * @date Fri Sep 22 01:29:43 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
  const int const_var = 1;

  /* compile error */
  /*const_var = 2;*/

  printf("value of const_var: %d before\n", const_var);

  union {
    const int *const_var;
    int *var;
  } __u;

  __u.const_var = &const_var;
  *(__u.var) = 2;

  printf("value of const_var: %d after\n", const_var);
  return 0;
}

