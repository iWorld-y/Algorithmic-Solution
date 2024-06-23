package LeetCode

// DSU Disjoint_Set_Union
type DSU struct {
	pa   []int
	size []int
}

func NewDSU(length int) *DSU {
	pa := make([]int, length)
	size := make([]int, length)
	for i := 0; i < length; i++ {
		pa[i] = i
		size[i] = i
	}
	return &DSU{
		pa:   pa,
		size: size,
	}
}

// Find 给出 x 所属的集合
func (d *DSU) Find(x int) int {
	// 若 x 的父节点指向自身, 即 x 为当前集合的代表元素
	if d.pa[x] != x {
		// 路径压缩, 让 x 直接指向根节点
		d.pa[x] = d.Find(d.pa[x])
	}
	return d.pa[x]
}

// Union 把 x 所属集合并入 y 所属集合
func (d *DSU) Union(x, y int) {
	x, y = d.Find(x), d.Find(y)
	if x == y {
		return
	}

	// 让 y 代表深度小的那棵树
	if d.size[x] < d.size[y] {
		x, y = y, x
	}
	// 把更小的树合入更大的树中
	d.pa[y] = x
	d.size[x] += d.size[y]
}

func findCircleNum(isConnected [][]int) int {
	dsu := NewDSU(len(isConnected))
	for a, cities := range isConnected {
		for b, city := range cities {
			if city != 0 && a != b {
				dsu.Union(a, b)
			}
		}
	}
	set := make(map[int]struct{})
	for _, v := range dsu.pa {
		set[dsu.Find(v)] = struct{}{}
	}
	return len(set)
}
