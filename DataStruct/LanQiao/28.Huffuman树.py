"""
:Author:    iWorld
:Create:    2022/3/8 20:18
:Abstract:  
"""
from typing import List


def main() -> None:
    n, arr = int(input()), input().split()
    arr = sorted([int(i) for i in arr])[::-1]
    right = len(arr) - 1
    ans = 0
    while (right > 1):
        # print(f"{ans}\t{temp}\t{arr[:right + 1]}")
        temp = arr[right] + arr[right - 1]
        arr[right - 1] = temp
        ans += temp
        arr = sorted([arr[i] for i in range(right)])[::-1]
        right -= 1
    print(ans + arr[0] + arr[1])
    return


if __name__ == '__main__':
    main()
