"""
@Time    : 2023/3/2 13:05
@Author  : Eugene
@FileName: 498.回文日期.py 
"""


def reverse_int(num: int) -> str:
    ans = 0
    start_with_0: bool = (num % 10 == 0)
    while (num > 0):
        ans *= 10
        ans += num % 10
        num //= 10
    return f"0{ans}" if start_with_0 else f"{ans}"


def is_legal(ans: str) -> bool:
    l = 0
    r = len(ans) - 1
    while (l < r):
        if (ans[l] != ans[r]):
            return False
        l += 1
        r -= 1
    return True


def get_ans(year: int):
    month = reverse_int(year)
    loop = int(month[:2])


def main():
    s = input()
    year = int(s[:4])
    print(f"{year + 1}{reverse_int(year + 1)}")
    print(is_legal(s))


main()
