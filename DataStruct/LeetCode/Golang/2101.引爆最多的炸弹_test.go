package LeetCode

import (
	"testing"
)

type tCase struct {
	bombs [][]int
	ans   int
}

func Test_maximumDetonation(t *testing.T) {
	var tcase []tCase
	//tcase = append(tcase, tCase{
	//	bombs: [][]int{{2, 1, 3}, {6, 1, 4}},
	//	ans:   2,
	//})
	//tcase = append(tcase, tCase{
	//	bombs: [][]int{{1, 1, 5}, {10, 10, 5}},
	//	ans:   1,
	//})
	//tcase = append(tcase, tCase{
	//	bombs: [][]int{{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}},
	//	ans:   5,
	//})
	//tcase = append(tcase, tCase{
	//	bombs: [][]int{{7, 26, 7}, {7, 18, 4}, {3, 10, 7}, {17, 50, 1}, {3, 25, 10}, {85, 23, 8}, {80, 50, 1}, {58, 74, 1}, {38, 39, 7}, {50, 51, 8}, {31, 99, 3}, {53, 6, 5}, {59, 27, 10}, {87, 78, 9}, {68, 58, 3}},
	//	ans:   3,
	//})
	tcase = append(tcase, tCase{
		bombs: [][]int{{855, 82, 158}, {17, 719, 430}, {90, 756, 164}, {376, 17, 340}, {691, 636, 152}, {565, 776, 5}, {464, 154, 271}, {53, 361, 162}, {278, 609, 82}, {202, 927, 219}, {542, 865, 377}, {330, 402, 270}, {720, 199, 10}, {986, 697, 443}, {471, 296, 69}, {393, 81, 404}, {127, 405, 177}},
		ans:   9,
	})
	for _, tc := range tcase {
		if ans := maximumDetonation(tc.bombs); ans != tc.ans {
			t.Fatalf("want %d, got %d\narr: %+v\n", tc.ans, ans, tc.bombs)
		}
	}
}
