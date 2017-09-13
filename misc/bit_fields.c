/**
 * bit fields in C
 * @date Wed Sep 13 14:55:35 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

#include <stdio.h>

#define print_type_size(type) \
  ({ printf("size of [%s]: %ld\n", #type, sizeof(type)); })

/**
 * struct without bit fields
 */
struct date {
  unsigned int d;
  unsigned int m;
  unsigned int y;
};

void print_date() {
  print_type_size(struct date);
  struct date dt = {13, 9, 2017};
  printf("date is %d/%d/%d\n", dt.d, dt.m, dt.y);
}

/**
 * struct with bit fields
 */
struct date_b {
  unsigned int d: 5;
  unsigned int m: 4;
  unsigned int y;
};

void print_date_b() {
  print_type_size(struct date_b);
  struct date_b dt = {13, 9, 2017};
  printf("date is %d/%d/%d\n", dt.d, dt.m, dt.y);
}


/**
 * without force alignment
 */
struct st_without_force_align {
  unsigned int x: 5;
  unsigned int y: 8;
};

/**
 * with force alignment
 */
struct st_with_force_align {
  unsigned int x: 5;
  unsigned int: 0;
  unsigned int y: 8;
};

int main(int argc, char *argv[]) {
  print_date();
  print_date_b();

  print_type_size(struct st_without_force_align);
  print_type_size(struct st_with_force_align);

  return 0;
}

