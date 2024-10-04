"""
:Author:    iWorld
:Create:    2022/2/23 23:48
:Abstract:  
"""


class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        arr = list(s)
        left, rigth = 0, len(arr) - 1
        while (rigth - left > 0):
            if (self.isAlpha(arr[left]) and self.isAlpha(arr[rigth])):
                temp = arr[left]
                arr[left] = arr[rigth]
                arr[rigth] = temp
                left += 1
                rigth -= 1
            elif (not self.isAlpha(arr[left])):
                left += 1
            elif (not self.isAlpha(arr[rigth])):
                rigth -= 1
        return ''.join(arr)

    def isAlpha(self, ch):
        if (ord('a') <= ord(ch) and ord(ch) <= ord('z')):
            return True
        elif (ord('A') <= ord(ch) and ord(ch) <= ord('Z')):
            return True
        else:
            return False


s = Solution()
print(s.reverseOnlyLetters("ab-cd"))
