from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [1]
        if (rowIndex == 0):
            return ans
        for rowI in range(rowIndex):
            temp = [1]
            left, right = 0, 1
            while (right < len(ans)):
                temp.append(ans[left] + ans[right])
                left += 1
                right += 1
            temp.append(1)
            ans = temp[:]
        return ans


s = Solution()
print(s.getRow(3))
