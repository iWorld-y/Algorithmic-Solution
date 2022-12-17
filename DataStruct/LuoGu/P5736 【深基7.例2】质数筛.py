def main() -> None:
    input()
    arr = [int(num) for num in input().split()]
    for num in arr:
        if (isPrime(num)):
            print(num, end=' ')


def isPrime(n: int) -> bool:
    if (n < 2):
        return False
    elif (n == 2 or n == 3):
        return True
    elif (n % 6 != 1 and n % 6 != 5):
        return False
    i = 5
    while (i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return False
        i += 6
    return True


main()
