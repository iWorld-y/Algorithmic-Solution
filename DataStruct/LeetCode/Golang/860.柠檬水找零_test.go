package LeetCode

import "testing"

type lemonCase struct {
	bills []int
	ret   bool
}

func Test_lemonadeChange(t *testing.T) {
	cases := []lemonCase{{
		bills: []int{5, 5, 5, 10, 20},
		ret:   true,
	}, {
		bills: []int{5, 5, 10, 10, 20},
		ret:   false,
	}, {
		bills: []int{5, 5, 5, 5, 20, 20, 5, 5, 5, 5},
		ret:   false,
	}}

	for i, v := range cases {
		if lemonadeChange(v.bills) != v.ret {
			t.Fatalf("%d 失败", i)
		}
	}
}
