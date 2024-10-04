from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        preSum = 0
        for i in range(len(nums)):
            if (preSum * 2 + nums[i] == total):
                return i
            preSum += nums[i]
        return -1


s = Solution()
print(s.pivotIndex([-1, -1, -1, -1, -1, -1]))
