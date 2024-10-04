from typing import List

"""
:Author:    iWorld
:Create:    2022/2/27 16:19
:Abstract:  
"""


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if not mat or not mat[0]:
            return []
        row, col = len(mat), len(mat[0])
        ans = []
        r, c, cnt = 0, 0, 0
        isUp = True
        while (cnt <= row * col):
            if (isUp):
                if (r - 1 < 0):
                    isUp = False
            if (not isUp):
                if (c):
                    pass


s = Solution()
print(s.findDiagonalOrder([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
