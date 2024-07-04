from typing import List


class Solution:
    # BFS
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        map: List[List[int]] = [[] for i in range(n)]
        for edge in edges:
            map[edge[0]].append(edge[1])
            map[edge[1]].append(edge[0])

        vis = [False] * n
        queue = [source]
        vis[source] = True
        while (len(queue) != 0):
            vertex = queue[0]
            queue.pop(0)
            if (vertex == destination):
                break
            for next in map[vertex]:
                if (not vis[next]):
                    queue.append(next)
                    vis[next] = True
        return vis[destination]


class Solution_:
    # DFS
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        map = [[] for i in range(n)]
        for edge in edges:
            map[edge[0]].append(edge[1])
            map[edge[1]].append(edge[0])
        vis = [False] * n
        return self.dfs(source, destination, map, vis)

    def dfs(self, source, destination, map, vis):
        if (source == destination):
            return True
        vis[source] = True
        for next in map[source]:
            if (not vis[next] and self.dfs(next, destination, map, vis)):
                return True
        return False


source = Solution()
# print(source.validPath(3, [[0, 1], [1, 2], [2, 0]], 0, 2))
print(source.validPath(6, [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]], 0, 5))
