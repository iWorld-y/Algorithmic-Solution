package LeetCode_test

import (
	"github.com/iWorld-y/Algorithmic-Solution/DataStruct/LeetCode"
	"testing"
)

func TestGetAncestors(t *testing.T) {
	t.Log(LeetCode.GetAncestors(8, [][]int{{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}}))
	t.Log(LeetCode.GetAncestors(9, [][]int{{3, 6}, {2, 4}, {8, 6}, {7, 4}, {1, 4}, {2, 1}, {7, 2}, {0, 4}, {5, 0}, {4, 6}, {3, 2}, {5, 6}, {1, 6}}))
}
