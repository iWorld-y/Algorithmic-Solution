package LeetCode

import "fmt"

// DSU Disjoint_Set_Union
type DSU struct {
	pa []int
}

func NewDSU(size int) *DSU {
	pa := make([]int, size)
	for i := 0; i < size; i++ {
		pa[i] = i
	}
	return &DSU{pa: pa}
}

// Find 给出 x 所属的集合
func (d *DSU) Find(x int) int {
	// 若 x 的父节点指向自身, 即 x 为当前集合的代表元素
	if d.pa[x] == x {
		return x
	}
	return d.Find(d.pa[x])
}

// Union 把 x 所属集合并入 y 所属集合
func (d *DSU) Union(x, y int) {
	d.pa[d.Find(x)] = d.Find(y)
}

func findCircleNum(isConnected [][]int) int {
	dsu := NewDSU(len(isConnected))
	for a, cities := range isConnected {
		for b, city := range cities {
			if city != 0 && a != b {
				fmt.Println(a, "\t->\t", b)
				dsu.Union(a, b)
			}
		}
	}
	set := make(map[int]struct{})
	for _, v := range dsu.pa {
		set[v] = struct{}{}
	}
	return len(set)
}
