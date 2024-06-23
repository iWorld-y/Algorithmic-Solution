package LeetCode

type DSU_ struct {
	root []int
	size []int
}

func NewDSU_(length int) *DSU_ {
	root := make([]int, length)
	size := make([]int, length)
	for i := 0; i < length; i++ {
		root[i] = i
		size[i] = 1
	}
	return &DSU_{
		root: root,
		size: size,
	}
}

func (d *DSU_) Find(x int) int {
	if d.root[x] != x {
		d.root[x] = d.Find(d.root[x])
	}
	return d.root[x]
}
func (d *DSU_) Union(x, y int) {
	rootX, rootY := d.Find(x), d.Find(y)
	if rootX != rootY {
		if d.size[rootX] < d.size[rootY] {
			rootX, rootY = rootY, rootX
		}
		d.root[rootY] = rootX
		d.size[rootX] += d.size[rootY]
	}
}
func maximumDetonation(bombs [][]int) int {
	if len(bombs) <= 1 {
		return len(bombs)
	}
	dsu := NewDSU_(len(bombs))
	for i := 0; i < len(bombs); i++ {
		for j := i + 1; j < len(bombs); j++ {
			if isSame(bombs[i], bombs[j]) {
				dsu.Union(i, j)
			}
		}
	}
	maxCnt := 0
	for i := 0; i < len(bombs); i++ {
		if newMax := dsu.size[i]; newMax > maxCnt {
			maxCnt = newMax
		}
	}
	return maxCnt
}

func distanceSquared(x1, y1, x2, y2 int) int {
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)
}

func isSame(x, y []int) bool {
	dist := distanceSquared(x[0], x[1], y[0], y[1])
	return dist <= x[2]*x[2] || dist <= y[2]*x[2]
}
