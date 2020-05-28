/*
 * @lc app=leetcode id=39 lang=golang
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (54.72%)
 * Likes:    3491
 * Dislikes: 108
 * Total Accepted:    514K
 * Total Submissions: 937.5K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */

// @lc code=start
// package leetcode

import (
	"sort"
)

func combinationSum(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	return doCombinationSum(candidates, target)
}

func doCombinationSum(candidates []int, target int) [][]int {
	result := [][]int{}

	for i, v := range candidates {
		if v == target {
			result = append(result, []int{v})
		} else if v < target {
			subResult := doCombinationSum(candidates[i:], target-v)
			for _, sr := range subResult {
				result = append(result, append([]int{v}, sr...))
			}
		} else {
			// v > target
			break
		}
	}

	return result
}

// @lc code=end
