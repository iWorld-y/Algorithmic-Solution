package LeetCode

import (
	"testing"
)

func TestIsPossibleToSplit(t *testing.T) {
	var arrList = []struct {
		arr []int
		ans bool
	}{
		{[]int{9, 9, 7, 5, 6, 3, 6, 4, 9, 5}, false},
		{[]int{1, 1, 2, 2, 3, 4}, true},
		{[]int{1, 1, 1, 1}, false},
	}
	for _, arr := range arrList {
		if ans := isPossibleToSplit(arr.arr); ans != arr.ans {
			t.Errorf("got %v, want %v", ans, arr.ans)
		}
	}
}
