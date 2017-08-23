//
// @file 014_last_remaining.cc
// @brief Find the last remaining number in a circle(Josephus Problem).
// 
// @version 1.0 
// @date Thu Jun 13 12:23:01 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <list>

#include <assert.h>

/// @brief Find the last remaining number in the circle.
///
/// @param n number of integers in the loop
/// @param m remove the mth number each time
///
/// @return The last remaining number.
int LastRemaining1(int n, int m) {
  assert(n >= 1);
  assert(m >= 1);

  std::list<int> integers;
  for (int i = 0; i < n; ++i) {
    integers.push_back(i);
  }

  std::list<int>::iterator current = integers.begin();
  std::list<int>::iterator next = integers.end();
  while (integers.size() > 1) {
    for (int i = 1; i < m; ++i) {
      if (++current == integers.end()) {
        current = integers.begin();
      }
    }

    if ((next = ++current) == integers.end()) {
      next = integers.begin();
    }

    --current;
    integers.erase(current);
    current = next;
  }

  return *current;
}

/// @brief Find the last remaining number in the circle.
///   f(n, m) = (f(n - 1, m) + m) % n
///
/// @param n number of integers in the loop
/// @param m remove the mth number each time
///
/// @return The last remaining number.
int LastRemaining2(int n, int m) {
  assert(n >= 1);
  assert(m >= 1);
  if (1 == n) {
    return 0;
  }

  return (LastRemaining2(n - 1, m) + m) % n;
}

/// @brief Find the last remaining number in the circle.
///   f(n, m) = (f(n - 1, m) + m) % n
///
/// @param n number of integers in the loop
/// @param m remove the mth number each time
///
/// @return The last remaining number.
int LastRemaining3(int n, int m) {
  assert(n >= 1);
  assert(m >= 1);

  // if there's only one integer in the circle initially,
  // the last remaining one is 0
  int last_integer = 0;

  // find the last remaining one in the circle with n integers
  for (int i = 2; i <= n; ++i) {
    last_integer = (last_integer + m) % i;
  }

  return last_integer;
}

int main(int argc, char* argv[]) {
  int n = 10;
  int m = 3;
  std::cout << LastRemaining1(n, m) << std::endl;
  std::cout << LastRemaining2(n, m) << std::endl;
  std::cout << LastRemaining3(n, m) << std::endl;
  return 0;
}

