package LeetCode

import (
	"sort"
)

func GetAncestors(n int, edges [][]int) [][]int {
	return getAncestors(n, edges)
}
func getAncestors(n int, edges [][]int) [][]int {
	in := make([][]int, n)
	ans := make([][]int, n)
	// 入度
	for _, edge := range edges {
		in[edge[1]] = append(in[edge[1]], edge[0])
	}
	var dfs func(curr, i int, visited []bool)
	dfs = func(curr, i int, visited []bool) {
		for _, next := range in[i] {
			if visited[next] {
				continue
			}
			visited[next] = true
			ans[curr] = append(ans[curr], next)
			dfs(curr, next, visited)
		}
	}
	for i := 0; i < n; i++ {
		dfs(i, i, make([]bool, n))
		ans[i] = CleanInts(ans[i])
	}
	return ans
}

func UniqueInt(arr []int) []int {
	m := make(map[int]int, len(arr))
	ans := make([]int, 0, len(arr))
	for _, i := range arr {
		m[i]++
		if m[i] == 1 {
			ans = append(ans, i)
		}
	}
	return ans
}

func CleanInts(arr []int) []int {
	arr = UniqueInt(arr)
	sort.Ints(arr)
	return arr
}
