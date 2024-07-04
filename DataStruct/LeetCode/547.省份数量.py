from typing import List


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        num = len(isConnected)
        unionFind = UnionFastFind(num)
        for city in range(num):
            for connnectedCity in range(num):
                if isConnected[city][connnectedCity] != 0:
                    unionFind.union(city, connnectedCity)
        return len(set(unionFind.ids))


class FastUnionFind:
    def __init__(self, n):
        self.fa = [i for i in range(n)]

    def find(self, x):
        while self.fa[x] != x:
            x = self.fa[x]
        return x

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x == root_y:
            return False
        self.fa[root_x] = self.fa[root_y]


class UnionFastFind:
    def __init__(self, n):
        self.ids = [i for i in range(n)]

    def find(self, x):
        return self.ids[x]

    def union(self, x, y) -> bool:
        """
        将 y 集合合并到 x 集合中
        """
        x_id = self.find(x)
        y_id = self.find(y)

        if x_id == y_id: return False
        for i in range(len(self.ids)):
            if self.find(i) == y_id:
                self.ids[i] = x_id
        return True

    def isConnected(self, x, y):
        return self.find(x) == self.find(y)


print(Solution().findCircleNum([[1, 1, 0], [1, 1, 0], [0, 0, 1]]))
print(Solution().findCircleNum([[1, 0, 0], [0, 1, 0], [0, 0, 1]]))
