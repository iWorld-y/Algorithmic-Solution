package LeetCode

import (
	"container/heap"
	"sort"
)

var a []int

type hp struct {
	sort.IntSlice
}

func (h *hp) Less(i, j int) bool {
	return a[h.IntSlice[i]] > a[h.IntSlice[j]]
}

func (h *hp) Push(value any) {
	h.IntSlice = append(h.IntSlice, value.(int))
}

func (h *hp) Pop() any {
	length := len(h.IntSlice)
	v := h.IntSlice[length-1]
	h.IntSlice = h.IntSlice[:length-1]
	return v
}

func maxSlidingWindow(nums []int, k int) []int {
	a = nums
	queue := &hp{make([]int, k)}
	for i := 0; i < k; i++ {
		queue.IntSlice[i] = i
	}
	heap.Init(queue)
	length := len(nums)
	ans := make([]int, 1, length-k+1)
	ans[0] = nums[queue.IntSlice[0]]
	for i := k; i < len(nums); i++ {
		heap.Push(queue, i)
		for queue.IntSlice[0] <= i-k {
			heap.Pop(queue)
		}
		ans = append(ans, nums[queue.IntSlice[0]])
	}
	return ans
}
