package LeetCode

//	func getAncestors(n int, edges [][]int) [][]int {
//		in := make([][]int, n)
//		ans := make([][]int, n)
//		// 入度
//		for _, edge := range edges {
//			in[edge[1]] = append(in[edge[1]], edge[0])
//		}
//
//		// i: curr 的某个祖先
//		var dfs func(curr, i int, visited []bool)
//		dfs = func(curr, i int, visited []bool) {
//			for _, next := range in[i] {
//				if visited[next] {
//					continue
//				}
//				visited[next] = true
//				ans[curr] = append(ans[curr], next)
//				dfs(curr, next, visited)
//			}
//		}
//		for i := 0; i < n; i++ {
//			dfs(i, i, make([]bool, n))
//			sort.Ints(ans[i])
//		}
//		return ans
//	}
func getAncestors(n int, edges [][]int) [][]int {
	in := make(map[int][]int, n)
	out := make(map[int]int, n)
	ans := make([][]int, n)
	queue := make([]int, 0, n)
	for _, edge := range edges {
		in[edge[1]] = append(in[edge[1]], edge[0])
		out[edge[0]]++
	}
	for i := 0; i < n; i++ {
		if _, ok := out[i]; !ok {
			queue = append(queue, i) // 找出度为 0 的点
		}
	}
	var dfs func(curr, parent int, visited []bool) []int
	dfs = func(curr, parent int, visited []bool) []int {
		if len(in[parent]) == 0 {
			return []int{parent}
		}
		for _, next := range edges[curr] {
			if visited[next] {
				continue
			}
			visited[parent] = true
			ans[parent] = append(ans[parent], dfs(curr, next, visited)...)
		}
		return ans[parent]
	}
	for i := range queue {
		ans[i] = append(ans[i], dfs(i, i, make([]bool, n))...)
	}
	return nil
}
