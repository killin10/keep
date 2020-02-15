// Package lc0107 solves leetcode problem 107 (Easy).
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
package lc0107

// TreeNode is a node of a binary tree
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrderBottom(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}

	ans := [][]int{}
	// ans = dfs(root, 0, ans)
	ans = bfs([]*TreeNode{root}, ans)

	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return ans
}

func dfs(node *TreeNode, depth int, ans [][]int) [][]int {
	if len(ans) <= depth {
		ans = append(ans, []int{})
	}

	ans[depth] = append(ans[depth], node.Val)
	if node.Left != nil {
		ans = dfs(node.Left, depth+1, ans)
	}
	if node.Right != nil {
		ans = dfs(node.Right, depth+1, ans)
	}

	return ans
}

func bfs(nodes []*TreeNode, ans [][]int) [][]int {
	nextLevel := []*TreeNode{}
	values := []int{}

	for _, node := range nodes {
		values = append(values, node.Val)

		if node.Left != nil {
			nextLevel = append(nextLevel, node.Left)
		}
		if node.Right != nil {
			nextLevel = append(nextLevel, node.Right)
		}
	}
	ans = append(ans, values)

	if len(nextLevel) == 0 {
		return ans
	}
	return bfs(nextLevel, ans)
}
