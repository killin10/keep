/*
 * @lc app=leetcode id=40 lang=golang
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (46.87%)
 * Likes:    1586
 * Dislikes: 64
 * Total Accepted:    312.1K
 * Total Submissions: 664.7K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 */

// @lc code=start
// package leetcode

import (
	"sort"
)

func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	return doCombinationSum(candidates, target)
}

func doCombinationSum(candidates []int, target int) [][]int {
	result := [][]int{}

	for i, v := range candidates {
		if i > 0 && v == candidates[i-1] {
			continue
		}
		if v == target {
			result = append(result, []int{v})
		} else if v < target {
			subResult := doCombinationSum(candidates[i+1:], target-v)
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
