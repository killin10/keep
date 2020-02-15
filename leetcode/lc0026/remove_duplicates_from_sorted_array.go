// Package lc0026 solves leetcode problem 26 (Easy).
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
package lc0026

// RemoveDuplicates remove duplicates from a given sorted array in-place.
func RemoveDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	last := 0
	for i := 1; i < len(nums); i++ {
		if nums[last] == nums[i] {
			continue
		}
		if last+1 != i {
			nums[last+1] = nums[i]
		}
		last++

	}
	return last + 1
}
