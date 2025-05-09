package LeetCode

/*
 * @lc app=leetcode.cn id=859 lang=golang
 *
 * [859] 亲密字符串
 */

// @lc code=start
func toSlice(s string) []rune {
	ret := make([]rune, 0, len(s))
	for _, ch := range s {
		ret = append(ret, ch)
	}
	return ret
}

func set(s string) []rune {
	setM := make(map[rune]struct{})
	for _, ch := range s {
		setM[ch] = struct{}{}
	}
	ret := make([]rune, 0, len(s))
	for ch := range setM {
		ret = append(ret, ch)
	}
	return ret
}

func buddyStrings(s string, goal string) bool {
	if len(s) != len(goal) {
		return false
	}
	if s == goal {
		sSet := set(s)
		return len(sSet) < len(goal)
	}

	var diffIdxs []int
	sslice := toSlice(s)
	gslice := toSlice(goal)
	for i := range len(sslice) {
		if sslice[i] != gslice[i] {
			diffIdxs = append(diffIdxs, i)
		}
	}
	if len(diffIdxs) != 2 {
		return false
	}
	sslice[diffIdxs[0]], sslice[diffIdxs[1]] = sslice[diffIdxs[1]], sslice[diffIdxs[0]]
	if string(sslice) != goal {
		return false
	}
	return true
}

// @lc code=end
