#
# @lc app=leetcode.cn id=191 lang=python3
#
# [191] 位1的个数
#

# @lc code=start
from curses.ascii import SO
from re import S


class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while(n):
            n = n & (n-1)
            ans += 1
        return ans


# @lc code=end
s = Solution()
print(s.hammingWeight())
