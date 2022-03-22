"""
:Author:    iWorld
:Create:    2022/3/8 20:35
:Abstract:  
"""


def main():
    arr = {0: "zero", 1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six", 7: "seven",
           8: "eight", 9: "nine", 10: "ten",
           11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen", 15: "fifteen", 16: "sixteen",
           17: "seventeen", 18: "eighteen",
           19: "nineteen", 20: "twenty", 30: "thirty", 40: "forty", 50: "fifty"}
    # h, m = int(input()), int(input())
    h = input().split()
    m = int(h[1])
    h = int(h[0])
    if (h > 20):
        print(f"{arr[20]} {arr[h - 20]}", end=" ")
    else:
        print(f"{arr[h]}", end=" ")

    if (m == 0):
        print("o'clock")
    elif (m > 20):
        print(f"{arr[m - m % 10]} {arr[m % 10]}")
    else:
        print(f"{arr[m]}")


if __name__ == '__main__':
    main()
