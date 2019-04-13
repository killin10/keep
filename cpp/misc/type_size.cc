#include <stdio.h>

#define print_type_size(type) \
  ({ printf("size of [%s]: %ld\n", #type, sizeof(type)); })

int main(int argc, char* argv[]) {
  print_type_size(bool);
  print_type_size(char);
  print_type_size(short);
  print_type_size(int);
  print_type_size(long);
  print_type_size(long long);
  print_type_size(float);
  print_type_size(double);
  print_type_size(long double);
  print_type_size(void*);

  return 0;
}

