package LeetCode

import (
	"fmt"
	"testing"
)

func Test_threeSum(t *testing.T) {
	fmt.Println(threeSum([]int{-1, 0, 1, 2, -1, -4}))
	fmt.Println(threeSum([]int{3, 0, -2, -1, 1, 2})) // [[-2,-1,3],[-2,0,2],[-1,0,1]]
	fmt.Println(threeSum([]int{0, 0, 0, 0}))
	fmt.Println(threeSum([]int{0, 1, 1}))
	t.Log("----")
}
