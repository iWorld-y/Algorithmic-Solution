def main():
    n = int(input())
    print(solve(n))


def solve(n: int) -> int:
    half_n = n / 2
    cnt = 0
    for i in range(1, n):
        if (i ** 2 % n < half_n):
            cnt += 1
    return cnt


main()
