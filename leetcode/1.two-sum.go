/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

// @lc code=start
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

