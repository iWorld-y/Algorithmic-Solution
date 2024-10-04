from typing import List

"""
:Author:    iWorld
:Create:    2022/2/22 2:15
:Abstract:  
"""


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits) - 1
        # [1, 3, 9, 9]
        if (digits[i] != 9):
            digits[i] += 1
            return digits
        else:
            digits[i] = 0
            i -= 1

            while (i >= 0):
                if (digits[i] == 9):
                    digits[i] = 0
                    i -= 1
                    continue
                else:
                    digits[i] += 1
                    return digits

            if (i < 0):
                digits.insert(0, 1)
                return digits


s = Solution()
print(s.plusOne([0,0,0]))
