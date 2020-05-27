/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.36%)
 * Likes:    14821
 * Dislikes: 536
 * Total Accepted:    2.9M
 * Total Submissions: 6.4M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 */

// @lc code=start
// package leetcode

func twoSum(nums []int, target int) []int {
	numToIndex := make(map[int]int)

	for i, v := range nums {
		complement := target - v
		ci, ok := numToIndex[complement]
		if ok {
			return []int{ci, i}
		}
		numToIndex[v] = i
	}
	return []int{-1, -1}
}

// @lc code=end
