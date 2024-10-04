package LeetCode

import "sort"

func getAncestors(n int, edges [][]int) [][]int {
	inMap := make(map[int][]int)
	ans := make([][]int, n)
	for _, edge := range edges {
		inMap[edge[1]] = append(inMap[edge[1]], edge[0])
	}

	var dfs func(curr, i int, visited []bool)
	dfs = func(curr, i int, visited []bool) {
		if len(inMap[i]) == 0 {
			return
		}
		for _, next := range inMap[i] {
			if visited[next] {
				continue
			}
			ans[curr] = append(ans[curr], next)
			visited[next] = true
			dfs(curr, next, visited)
		}
	}

	for i := 0; i < n; i++ {
		dfs(i, i, make([]bool, n))
		sort.Ints(ans[i])
	}
	return ans
}
