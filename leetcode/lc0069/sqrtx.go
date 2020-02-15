// Package lc0069 solves leetcode problem 69 (Easy).
// https://leetcode.com/problems/sqrtx/description/
package lc0069

// SqrtNewton calculate sqrt(x) using Newton iteration.
func SqrtNewton(x int) int {
	r := x
	for r*r > x {
		r = (r + x/r) / 2
	}
	return r
}

// SqrtBinarySearch calculate sqrt(x) using binary search.
func SqrtBinarySearch(x int) int {
	low, high := 0, x
	for low < high {
		mid := (low + high) / 2
		sq := mid * mid
		if sq > x {
			high = mid
		} else if sq < x {
			low = mid + 1
		} else {
			return mid
		}
	}
	return high - 1
}
