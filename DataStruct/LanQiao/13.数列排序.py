def main():
    a = int(input())
    if (a != 1):
        a = [int(i) for i in input().split()]
    else:
        a = int(input())
        print(a)
        return
    for i in sorted(a):
        print(i, end=" ")


main()
