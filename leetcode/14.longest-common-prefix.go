/*
 * @lc app=leetcode id=14 lang=golang
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.05%)
 * Likes:    2392
 * Dislikes: 1805
 * Total Accepted:    722.9K
 * Total Submissions: 2.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
 *
 */

// @lc code=start
package leetcode

func longestCommonPrefix(strs []string) string {
	vals := [][]rune{}
	for _, v := range strs {
		vals = append(vals, []rune(v))
	}

	prefix := []rune{}
	i := 0
	for {
		for _, v := range vals {

		}
	}
}

// @lc code=end
