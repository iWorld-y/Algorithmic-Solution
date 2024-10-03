package LeetCode

import "sort"

func threeSum(nums []int) [][]int {
	length := len(nums)
	sort.Ints(nums)
	ans := make([][]int, 0)
	for first := 0; first < length; first++ {
		if first > 0 && nums[first] == nums[first-1] {
			// 重复的 first
			continue
		}
		third := length - 1
		for second := first + 1; second < length; second++ {
			if second > first+1 && nums[second-1] == nums[second] {
				// 重复的 second
				continue
			}
			sum := nums[first] + nums[second] + nums[third]
			for second < third && sum > 0 {
				third--
				sum = nums[first] + nums[second] + nums[third]
			}
			if second >= third {
				break
			}
			if sum == 0 {
				ans = append(ans, []int{nums[first], nums[second], nums[third]})
			}
		}
	}
	return ans
}
