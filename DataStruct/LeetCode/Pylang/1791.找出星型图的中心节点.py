from typing import List


class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        n = (len(edges) + 1)
        indegree = [0] * n
        for edge in edges:
            indegree[edge[0] - 1] += 1
            indegree[edge[1] - 1] += 1
        m, ans = -1, -1
        for i in range(n):
            if (indegree[i] > m):
                m = indegree[i]
                ans = i + 1
        return ans


source = Solution()
print(source.findCenter([[1, 2], [2, 3], [4, 2]]))
print(source.findCenter([[1, 2], [5, 1], [1, 3], [1, 4]]))
