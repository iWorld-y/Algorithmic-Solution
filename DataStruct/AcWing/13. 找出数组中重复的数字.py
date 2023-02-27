class Solution(object):
    def duplicateInArray(self, nums):
        """
        :type nums: List[int]
        :rtype int
        """
        if (not nums): return -1
        nums = sorted(nums)
        l = len(nums)
        if (nums[0] < 0 or nums[l - 1] >= l): return -1
        for i in range(1, l):
            if (nums[i - 1] == nums[i]):
                return nums[i]
        return -1


s = Solution()
print(s.duplicateInArray([3, 1, -10, 1, 1, 4, 3, 10, 1, 1]))
print(s.duplicateInArray([]))
print(s.duplicateInArray([1, 1, 100, 1]))
print(s.duplicateInArray([0, 4, 2, 3, 4]))
