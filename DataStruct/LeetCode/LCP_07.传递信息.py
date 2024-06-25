from typing import List

from collections import defaultdict


class Solution:
    def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
        # 构建邻接列表
        adj = defaultdict(list)
        for edge in relation:
            src, dest = edge[0], edge[1]
            adj[src].append(dest)

        # 使用深度优先搜索计算传递方案数
        self.num_paths = 0
        self.dfs(0, k, adj, n - 1)
        return self.num_paths

    def dfs(self, curr, steps, adj, target):
        # 达到目标步数并且当前位置是目标位置
        if steps == 0 and curr == target:
            self.num_paths += 1
            return

        # 如果还有步数可用，则继续向下传递
        if steps > 0:
            for neighbor in adj[curr]:
                self.dfs(neighbor, steps - 1, adj, target)


source = Solution()
print(source.numWays(n=5, relation=[[0, 2], [2, 1], [3, 4], [2, 3], [1, 4], [2, 0], [0, 4]], k=3))
print(source.numWays(n=3, relation=[[0, 2], [2, 1]], k=2))
