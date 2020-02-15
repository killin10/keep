// Package lc0070 solves leetcode problem 70 (Easy).
// https://leetcode.com/problems/climbing-stairs/description/
package lc0070

// ClimbStairs calculates how many distinct ways can you climb to the top in a given n steps.
func ClimbStairs(n int) int {
	f1, f2 := 0, 1
	next := 0
	for i := 1; i <= n; i++ {
		next = f1 + f2
		f1 = f2
		f2 = next
	}
	return next
}
