// Package lc0001 solves leetcode problem 1 (Easy).
// https://leetcode.com/problems/two-sum/description/
package lc0001

// TwoSum solve the problem with Brute Force method in O(n^2) complexity.
func TwoSum(nums []int, target int) []int {
	size := len(nums)

	for i := 0; i < size-1; i++ {
		for j := i + 1; j < size; j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}

	return []int{-1, -1}
}

// TwoSumWith2PassHashTable solve the problem using an extra hash table
// which reduces the time complexity to O(n).
func TwoSumWith2PassHashTable(nums []int, target int) []int {
	numToIndex := make(map[int]int)
	for i, v := range nums {
		numToIndex[v] = i
	}

	for i, v := range nums {
		complement := target - v
		ci, ok := numToIndex[complement]
		if ok && ci != i {
			return []int{i, ci}
		}
	}

	return []int{-1, -1}
}

// TwoSumWith1PassHashTable is similar with TwoSumWith2PassHashTable,
// but tranverse the list only once.
func TwoSumWith1PassHashTable(nums []int, target int) []int {
	numToIndex := make(map[int]int)

	for i, v := range nums {
		complement := target - v
		ci, ok := numToIndex[complement]
		if ok {
			return []int{i, ci}
		}

		numToIndex[v] = i
	}

	return []int{-1, -1}
}
