#
# @lc app=leetcode.cn id=1455 lang=python3
#
# [1455] 检查单词是否为句中其他单词的前缀
#

# @lc code=start
class Solution:
    def isPrefix(self, sentence: str, searchWord: str, start: int, end: int) -> bool:
        n = len(searchWord)
        for i in range(n):
            if(start+i >= end or sentence[start+i] != searchWord[i]):
                return False
        return True

    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        indx = 1
        start, end = 0, 0
        n = len(sentence)
        while(start < n):
            while(end < n and sentence[end] != ' '):
                end += 1
            if(self.isPrefix(sentence, searchWord, start, end)):
                return indx
            indx += 1
            end += 1
            start = end
        return -1

# @lc code=end
