#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
import math


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        minprice = math.inf
        for price in prices:
            maxprofit = max(maxprofit, price-minprice)
            minprice = min(minprice, price)
        return maxprofit
# @lc code=end
