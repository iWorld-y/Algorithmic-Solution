import os
import sys


def main() -> None:
    n = int(input())
    arr = []
    for i in range(n):
        arr.append([int(num) for num in input().split()])
    print(MaxSum(n, arr))


def MaxSum(n: int, arr: list) -> int:
    for i in range(n - 1, -1, -1):
        for j in range(i + 1):
            arr[i][j] = max(arr[i + 1][j], arr[i + 1][j + 1] + arr[i][j])
    return arr[1][1]


main()
