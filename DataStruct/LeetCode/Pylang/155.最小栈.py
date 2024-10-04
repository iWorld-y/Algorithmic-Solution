#
# @lc app=leetcode.cn id=155 lang=python3
#
# [155] 最小栈
#

# @lc code=start
import math


class MinStack:

    def __init__(self):
        self.s = []
        self.minS = [math.inf]

    def push(self, val: int) -> None:
        # 每一次都存入当前栈中的最小值, 哪怕有重复
        self.minS.append(min(val, self.minS[-1]))
        self.s.append(val)

    def pop(self) -> None:
        self.s.pop()
        self.minS.pop()

    def top(self) -> int:
        return self.s[-1]

    def getMin(self) -> int:
        return self.minS[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end
