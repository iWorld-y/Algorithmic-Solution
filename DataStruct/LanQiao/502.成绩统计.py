"""
@Time    : 2023/3/2 12:57
@Author  : Eugene
@FileName: 502.成绩统计.py 
"""


def main():
    num = int(input())
    passNum = 0
    excelNum = 0
    for i in range(num):
        score = int(input())
        if (60 <= score and score < 85):
            passNum += 1
        elif (score >= 85):
            excelNum += 1
            passNum += 1
    print(f"{round(passNum / num * 100)}%")
    print(f"{round(excelNum / num * 100)}%")


main()
