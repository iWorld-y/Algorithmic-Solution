def main():
    a = 1
    b = 1
    c = 3
    d = 0
    i = 4
    while (i <= 20190323):
        d = (a + b + c) % 10000
        a = b
        b = c
        c = d
        i += 1
    print("%d" % d)


main()
