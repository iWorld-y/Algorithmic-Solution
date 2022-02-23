from typing import List
"""
:Author:    iWorld
:Create:    2022/2/22 2:13
:Abstract:  
"""

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        nums[:] = self.reverse(nums, 0, len(nums) - 1)
        nums[:k] = self.reverse(nums, 0, k - 1)
        nums[k:] = self.reverse(nums, k, len(nums) - 1)
        print(nums)

    def reverse(self, arr: List[int], left: int, right: int) -> List:
        l = left
        r = right
        while (left < right):
            t = arr[left]
            arr[left] = arr[right]
            arr[right] = t
            left += 1
            right -= 1
        return arr[l:r + 1]


# nums = [1, 2, 3, 4, 5, 6, 7]
# k = 3
nums = [-1]
k = 2
s = Solution()
s.rotate(nums=nums, k=k)
