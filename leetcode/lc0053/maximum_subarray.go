// Package lc0053 solves leetcode problem 53 (Easy).
// https://leetcode.com/problems/maximum-subarray/description/
package lc0053

// MaxSubArray finds out the largest sum of contiguous subarray within a given array.
func MaxSubArray(nums []int) int {
	current := nums[0]
	max := current
	for i := 1; i < len(nums); i++ {
		if current < 0 {
			current = nums[i]
		} else {
			current += nums[i]
		}
		if current > max {
			max = current
		}
	}

	return max
}

type retVal struct {
	l int // sum of the sub array with largest sum starting from the first
	r int // sum of the sub array with largest sum ending at the last
	m int // sum of the sub array with the largest sum
	s int // sum of the whole array
}

// MaxSubArrayByDivideAndConquer finds out the sum of sub array with the largest sum using Divide And Conquer
func MaxSubArrayByDivideAndConquer(nums []int) int {
	v := calc(nums, len(nums))
	return v.m
}

func calc(nums []int, n int) retVal {
	if n == 1 {
		return retVal{nums[0], nums[0], nums[0], nums[0]}
	}

	v1, v2 := calc(nums, n/2), calc(nums[n/2:], n-n/2)
	return retVal{
		max(v1.l, v1.s+v2.l),
		max(v1.r+v2.s, v2.r),
		max(v1.r+v2.l, max(v1.m, v2.m)),
		v1.s + v2.s,
	}
}

func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}
