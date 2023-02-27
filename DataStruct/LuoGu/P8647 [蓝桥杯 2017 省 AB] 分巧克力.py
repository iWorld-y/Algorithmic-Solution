def main():
    n, k = [int(i) for i in input().split()]
    chocolates = []
    for i in range(n):
        h, w = [int(i) for i in input().split()]
        chocolates.append(Chocolate(h, w))
    l = 0
    r = 100007
    while (l <= r):
        m = (l + r) // 2


class Chocolate:
    def __init__(self, h, w):
        self.h = h
        self.w = w


main()
