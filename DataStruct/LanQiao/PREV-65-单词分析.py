import os
import sys


# 请在此输入您的代码
def main():
    word = input()
    arr = [0] * 26
    ans = ''
    maxCnt = 0
    for i in word:
        latterAscii = ord(i) - 97
        arr[latterAscii] += 1
        if (maxCnt < arr[latterAscii]):
            maxCnt = arr[latterAscii]
            ans = i
    print(ans)
    print(maxCnt)


main()