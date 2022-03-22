"""
:Author:    iWorld
:Create:    2022/3/8 19:53
:Abstract:  
"""


def main():
    n = int(input())
    if (n == 0):
        print(1)
        return
    ans = 1
    for i in range(1, n + 1):
        ans *= i
    print(ans)


main()
