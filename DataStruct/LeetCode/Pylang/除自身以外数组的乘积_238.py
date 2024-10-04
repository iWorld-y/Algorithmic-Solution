from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        larr, rarr = [0] * length, [0] * length
        # larr, rarr, ans = [0] * length, [0] * length, [0] * length
        larr[0] = 1
        for i in range(1, length):
            larr[i] = nums[i - 1] * larr[i - 1]
        rarr[length - 1] = 1
        for i in range(length - 2, -1, -1):
            rarr[i] = rarr[i + 1] * nums[i + 1]
        for i in range(length):
            nums[i] = larr[i] * rarr[i]
        return nums


s = Solution()
print(s.productExceptSelf([-1, 1, 0, -3, 3]))
