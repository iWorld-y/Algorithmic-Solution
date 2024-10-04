package LeetCode

import "sort"

func isPossibleToSplit(nums []int) bool {
	sort.Ints(nums)
	var l, r = 0, 0
	for r < len(nums) {
		if nums[l] == nums[r] {
			if r-l >= 2 {
				return false
			}
			r++
			continue
		}
		if r-l > 2 {
			return false
		}
		l = r
	}
	return true
}
