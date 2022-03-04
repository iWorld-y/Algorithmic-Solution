import os
from random import randint

"""
:Author:    iWorld
:Create:    2022/2/28 11:06
:Abstract:  加减法速算练习
"""


def main():
    openAddition = True
    openSubtraction = True

    temp = input("是否开启加法? [y]/n")
    if ('n' in temp):
        openAddition = False
    temp = input("是否开启减法? [y]/n")
    if ('n' in temp):
        openSubtraction = False

    del temp
    if ((not openAddition) and (not openSubtraction)):
        print("加减法均未开启, 程序退出")
        return
    os.system("cls")
    while (True):
        num1 = randint(0, 101)
        num2 = randint(0, 101)
        isAddition = True if randint(0, 1) == 0 else False
        if (isAddition):
            try:
                ans = int(input(f"{num1} + {num2} = "))
            except ValueError as valueE:
                print(num1)
                print(valueE)
                continue
            if (ans != num1 + num2):
                print(f"Error! {num1} + {num2} = {num1 + num2}")
        else:

            try:
                ans = int(input(f"{num1} - {num2} = "))
            except ValueError as valueE:
                if (num1 == '#'):
                    return
                else:
                    print(valueE)
                    continue
            if (ans != num1 - num2):
                print(f"Error! {num1} - {num2} = {num1 - num2}")


if __name__ == '__main__':
    main()
