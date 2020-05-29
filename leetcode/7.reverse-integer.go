/*
 * @lc app=leetcode id=7 lang=golang
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.70%)
 * Likes:    3234
 * Dislikes: 5089
 * Total Accepted:    1.1M
 * Total Submissions: 4.2M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 *
 */

// @lc code=start
// package leetcode

const (
	MaxUint = ^uint32(0)
	MaxInt  = int32(MaxUint >> 1)
	MinInt  = -MaxInt - 1
)

func reverse(x int) int {
	r := 0

	for x != 0 {
		r = r*10 + x%10
		x = x / 10
	}

	if r > 0 && r > int(MaxInt) || r < 0 && r < int(MinInt) {
		return 0
	}

	return r
}

// @lc code=end
