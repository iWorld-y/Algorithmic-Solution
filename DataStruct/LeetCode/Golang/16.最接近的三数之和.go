package LeetCode

import (
	"fmt"
	"math"
	"sort"
)

func threeSumClosest(nums []int, target int) int {
	length := len(nums)
	if length <= 3 {
		return nums[0] + nums[1] + nums[2]
	}
	sort.Ints(nums)
	currSum := math.MaxInt32
	for first := 0; first < length; first++ {
		if first > 0 && nums[first-1] == nums[first] {
			continue
		}
		third := length - 1
		for second := first + 1; second < length; second++ {
			if second > first+1 && nums[second-1] == nums[second] {
				continue
			}
			sum := nums[first] + nums[second] + nums[third]
			for sum > target {
				third--
				sum = nums[first] + nums[second] + nums[third]
			}
			if second >= third {
				break
			}
			if distance(currSum, target) > distance(sum, target) {
				currSum = sum
				fmt.Printf("%d + %d + %d = %d\n", nums[first], nums[second], nums[third], sum)
			}
		}
	}
	return currSum
}
func abs(num int) int {
	if num > 0 {
		return num
	}
	return -num
}
func distance(curr, target int) int {
	return abs(target - curr)
}
