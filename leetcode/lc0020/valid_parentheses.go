// Package lc0020 solves leetcode problem 20 (Easy).
// https://leetcode.com/problems/valid-parentheses/description/
package lc0020

type stack []string

func (s stack) Push(v string) stack {
	return append(s, v)
}

func (s stack) Pop() (stack, string) {
	l := len(s)
	return s[:l-1], s[l-1]
}

func (s stack) IsEmpty() bool {
	return len(s) == 0
}

var parenthesesMapping = map[string]string{
	")": "(",
	"]": "[",
	"}": "{",
}

// IsValid tells whether the parentheses in the input is valid.
func IsValid(s string) bool {
	st := make(stack, 0)

	var left string
	for _, c := range s {
		cs := string(c)
		if _, ok := parenthesesMapping[cs]; !ok {
			st = st.Push(cs)
		} else {
			if st.IsEmpty() {
				return false
			}
			st, left = st.Pop()
			if left != parenthesesMapping[cs] {
				return false
			}
		}
	}
	return st.IsEmpty()
}
