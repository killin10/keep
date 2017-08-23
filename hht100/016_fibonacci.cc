//
// @file 016_fibonacci.cc
// @brief Calculate the nth item of Fibonacci Series.
// 
// @version 1.0 
// @date Thu Jun 13 20:57:56 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

/// @brief Calculate the nth item of Fibonacci Series recursively.
///
/// @param n the nth item
///
/// @return value of the nth item
int Fibonacci1(int n) {
  assert(n >= 0);

  if (1 == n) {
    return 1;
  }
  if (0 == n) {
    return 0;
  }
  return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}

/// @brief Calculate the nth item of Fibonacci Series iteratively.
///
/// @param n the nth item
///
/// @return  value of the nth item
int Fibonacci2(int n) {
  assert(n >= 0);

  int fb_one = 0;
  int fb_two = 1;
  int fb_n = 0;
  for (int i = 2; i <= n; ++i) {
    fb_n = fb_two + fb_one;
    fb_one = fb_two;
    fb_two = fb_n;
  }
  return fb_n;
}

// solution 3: Matrix multiplication

// A 2 by 2 matrix.
struct Matrix2By2 {
  int m00;
  int m01;
  int m10;
  int m11;

  Matrix2By2(int n00 = 0, int n01 = 0, int n10 = 0, int n11 = 0) :
    m00(n00), m01(n01), m10(n10), m11(n11) {}
};

// Multiply two matrixes.
Matrix2By2 MatrixMultiply(const Matrix2By2& mx1, const Matrix2By2& mx2) {
  return Matrix2By2(
      mx1.m00 * mx2.m00 + mx1.m01 * mx2.m10,
      mx1.m00 * mx2.m01 + mx1.m01 * mx2.m11,
      mx1.m10 * mx2.m00 + mx1.m11 * mx2.m10,
      mx1.m10 * mx2.m01 + mx2.m11 * mx2.m11
      );
}

/// @brief Power of matrix.
///
/// @param mx the matrix
/// @param n nth power
///
/// @return nth power the matrix
Matrix2By2 MatrixPower(const Matrix2By2& mx, int n) {
  assert(n > 0);

  Matrix2By2 matrix;
  if (1 == n) {
    matrix = mx;
  } else if (n % 2 == 0) {
    // n is even
    matrix = MatrixPower(mx, n / 2);
    matrix = MatrixMultiply(matrix, matrix);
  } else if (n % 2 == 1) {
    // n is odd
    matrix = MatrixPower(mx, (n - 1) / 2);
    matrix = MatrixMultiply(matrix, matrix);
    matrix = MatrixMultiply(matrix, mx);
  } else {
    // never reach here
  }

  return matrix;
}

int Fibonacci3(int n) {
  assert(n >= 0);

  if (0 == n) {
    return 0;
  }
  if (1 == n) {
    return 1;
  }

  Matrix2By2 mx(1, 1, 1, 0);
  return MatrixPower(mx, n - 1).m00;
}

int main(int argc, char* argv[]) {
  int n = 10;
  std::cout << Fibonacci1(n) << std::endl;
  std::cout << Fibonacci2(n) << std::endl;
  std::cout << Fibonacci3(n) << std::endl;
  return 0;
}

