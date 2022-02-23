from typing import List


class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        left = 0
        right = 0
        ans = 0
        for i in range(len(nums)):
            if (nums[right] == 1):
                right += 1
            else:
                ans = max(right - left, ans)
                right += 1
                left = right

        ans = max(right - left, ans)
        return ans


s = Solution()
print(s.findMaxConsecutiveOnes([1, 1, 0, 1, 1, 1]))
