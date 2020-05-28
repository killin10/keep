/*
 * @lc app=leetcode id=18 lang=golang
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (33.06%)
 * Likes:    1738
 * Dislikes: 312
 * Total Accepted:    318.6K
 * Total Submissions: 962.5K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 *
 *
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */

// @lc code=start
// package leetcode

import (
	"sort"
)

func fourSum(nums []int, target int) [][]int {
	result := [][]int{}

	sort.Ints(nums)
	for i := 0; i < len(nums)-3; i++ {
		v := nums[i]

		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		threeSums := threeSum(nums[i+1:], target - v)
		for _, ts := range threeSums {
			result = append(result, append([]int{v}, ts...))
		}
	}

	return result
}

func threeSum(nums []int, expected int) [][]int {
	result := [][]int{}

	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		target, left, right := expected -nums[i], i+1, len(nums)-1
		for left < right {
			sum := nums[left] + nums[right]
			if sum == target {
				result = append(result, []int{nums[i], nums[left], nums[right]})
				left++
				right--
				for left < right && nums[left] == nums[left-1] {
					left++
				}
				for left < right && nums[right] == nums[right+1] {
					right--
				}
			} else if sum > target {
				right--
			} else {
				left++
			}
		}
	}

	return result
}

// @lc code=end
