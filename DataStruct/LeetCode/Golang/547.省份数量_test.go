package LeetCode

import (
	"testing"
)

type Cases struct {
	arr [][]int
	ans int
}

func Test_findCircleNum(t *testing.T) {
	var c []Cases
	c = append(c, Cases{
		arr: [][]int{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}},
		ans: 2,
	})
	c = append(c, Cases{
		arr: [][]int{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
		ans: 3,
	})
	c = append(c, Cases{
		arr: [][]int{
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
			{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
			{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
			{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}},
		ans: 8,
	})
	for i, testCase := range c {
		if ans := findCircleNum(testCase.arr); ans != testCase.ans {
			t.Fatalf("error no.%d\t%+v\n\n\nwant %d, got %d", i+1, testCase.arr, testCase.ans, ans)
		}
	}
}
