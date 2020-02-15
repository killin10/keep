// Package lc0066 solves leetcode problem 66 (Easy).
// https://leetcode.com/problems/plus-one/description/
package lc0066

// PlusOne solve this fxxking problem.
func PlusOne(digits []int) []int {
	result := make([]int, len(digits)+1)
	overflow := 1
	for i := len(digits) - 1; i >= 0; i-- {
		sum := digits[i] + overflow
		if sum >= 10 {
			result[i+1] = sum % 10
			overflow = 1
		} else {
			result[i+1] = sum
			overflow = 0
		}
	}
	if overflow != 0 {
		result[0] = overflow
		return result
	}
	return result[1:]
}
