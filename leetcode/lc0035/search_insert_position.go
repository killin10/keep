// Package lc0035 solves leetcode problem 35 (Easy).
// https://leetcode.com/problems/search-insert-position/description/
package lc0035

// SearchInsert return the index if the target is found in a given sorted array and a target value,
// if not found, return the index where it would be if it were inserted in order.
func SearchInsert(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left <= right {
		mid := (left + right) / 2
		if target > nums[mid] {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return left
}

// SearchInsertRecursion return the index if the target is found in a given sorted array and a target value,
// if not found, return the index where it would be if it were inserted in order.
func SearchInsertRecursion(nums []int, target int) int {
	if len(nums) == 0 {
		return 0
	}
	return doSearch(nums, target, 0, len(nums)-1)
}

func doSearch(nums []int, target int, left int, right int) int {
	if left == right {
		if target <= nums[left] {
			return left
		}
		return left + 1
	}

	if left > right {
		return left
	}

	mid := (left + right) / 2
	if target == nums[mid] {
		return mid
	} else if target < nums[mid] {
		return doSearch(nums, target, left, mid-1)
	} else {
		return doSearch(nums, target, mid+1, right)
	}
}
