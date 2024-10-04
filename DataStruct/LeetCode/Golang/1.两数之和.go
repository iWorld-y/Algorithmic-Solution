package LeetCode

func twoSum(nums []int, target int) []int {
	numMap := make(map[int]int, len(nums))
	var ans [2]int
	for i, v := range nums {
		if idx, ok := numMap[target-v]; ok {
			ans[0] = i
			ans[1] = idx
			return ans[:]
		}
		numMap[v] = i
	}
	return ans[:]
}
