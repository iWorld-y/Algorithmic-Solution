#
# @lc app=leetcode.cn id=654 lang=python3
#
# [654] 最大二叉树
#

# @lc code=start
# Definition for a binary tree node.
from operator import le
from turtle import right
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        def construct(left: int, right: int):
            if(left > right):
                return
            best = left
            for i in range(left+1, right+1):
                if(nums[i] > nums[best]):
                    best = i
            node = TreeNode(nums[best])
            node.left = construct(left, best-1)
            node.right = construct(best+1, right)
            return node
        return construct(0, len(nums)-1)

# @lc code=end
