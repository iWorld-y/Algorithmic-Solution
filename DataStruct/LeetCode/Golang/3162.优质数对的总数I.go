package LeetCode

func numberOfPairs(nums1 []int, nums2 []int, k int) int {
	ans := 0
	for _, n1 := range nums1 {
		for _, n2 := range nums2 {
			if n1%(n2*k) == 0 {
				ans++
			}
		}
	}
	return ans
}
