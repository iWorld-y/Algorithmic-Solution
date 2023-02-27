def main():
    ans = 0
    for i in range(5):
        if (solve(int(input()))):
            ans += 1
    print(ans)


def solve(year: int) -> bool:
    year0 = year % 10
    year //= 10
    year1 = year % 10
    year //= 10
    year2 = year % 10
    year //= 10
    year3 = year % 10
    year //= 10
    return year3 == year1 and year0 - year2 == 1


main()