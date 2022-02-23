from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        size = len(matrix)
        maxIndx = size - 1
        for i in range(size):
            matrix[i][:] = matrix[i][::-1]
        for i in range(size):
            # print(matrix, end="\n\n")
            self.draw(matrix)
            for j in range(size - i):
                temp = matrix[i][j]
                matrix[i][j] = matrix[maxIndx - j][maxIndx - i]
                matrix[maxIndx - j][maxIndx - i] = temp

    def draw(self, matrix: List[List[int]]) -> None:
        print()
        for i in matrix:
            print(i)


s = Solution()
s.rotate([
    [5, 1, 9, 11],
    [2, 4, 8, 10],
    [13, 3, 6, 7],
    [15, 14, 12, 16]
])

# [11, 9, 1, 5]
# [10, 8, 4, 2]
# [7, 6, 3, 13]
# [16, 12, 14, 15]

# [1, 2, 3]
# [4, 5, 6]
# [7, 8, 9]
# # 镜像翻转
# [3, 2, 1]
# [6, 5, 4]
# [9, 8, 7]
# # 对角翻转
# [7, 4, 1]
# [8, 5, 2]
# [9, 6, 3]
