from typing import List

"""
:Author:    iWorld
:Create:    2022/2/23 23:02
:Abstract:  
"""


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        cSize, rSize = len(matrix), len(matrix[0])
        col = set()
        raw = set()
        for i in range(cSize):
            for j in range(rSize):
                if (matrix[i][j] == 0):
                    col.add(i)
                    raw.add(j)
        for i in col:
            matrix[i] = [0] * rSize
        for i in raw:
            for j in range(cSize):
                matrix[j][i] = 0
        self.draw(matrix)

    def draw(self, matrix: List[List[int]]) -> None:
        print()
        for i in matrix:
            print(i)


s = Solution()
s.setZeroes([
    [0, 1, 2, 0],
    [3, 4, 5, 2],
    [1, 3, 1, 5]
])
