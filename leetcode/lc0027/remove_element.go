// Package lc0027 solves leetcode problem 27 (Easy).
// https://leetcode.com/problems/remove-element/description/
package lc0027

// RemoveElement remove all instances of specified value from a given array.
func RemoveElement(nums []int, val int) int {
	last := -1
	for i := 0; i < len(nums); i++ {
		if nums[i] == val {
			continue
		}
		last++
		nums[last] = nums[i]
	}
	return last + 1
}

// RemoveElementUnordered remove all instances of specified value from a given array.
func RemoveElementUnordered(nums []int, val int) int {
	r := len(nums) - 1
	for i := 0; i <= r; {
		if nums[i] == val {
			nums[i] = nums[r]
			r--
		} else {
			i++
		}
	}
	return r + 1
}
