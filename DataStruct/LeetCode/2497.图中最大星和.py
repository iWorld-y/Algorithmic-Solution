from typing import List


class Solution:
    def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
        n = len(vals)
        if (n == 1): return vals[0]
        adj: List[List[int]] = [[] for i in range(n)]
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        vis: List[bool] = [False] * n
        # vis[edges[0][0]] = True
        queue = [edges[0][0]]
        ans = vals[0]
        while (queue):
            vertex = queue[0]
            queue.pop(0)
            if (vis[vertex]): continue
            vis[vertex] = True
            temp_ans = vals[vertex]
            near_vals = []
            for next in adj[vertex]:
                queue.append(next)
                near_vals.append(vals[next])
            near_vals = sorted(near_vals, reverse=True)
            for i in range(min(k, len(near_vals))):
                if (near_vals[i] > 0):
                    temp_ans += near_vals[i]
            ans = max(ans, temp_ans)
        return ans


s = Solution()
print(s.maxStarSum([1, 2, 3, 4, 10, -10, -20],
                   [[0, 1], [1, 2], [1, 3], [3, 4], [3, 5], [3, 6]],
                   2))
print(s.maxStarSum([-5], [], 0))
