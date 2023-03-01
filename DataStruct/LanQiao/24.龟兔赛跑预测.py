"""
@Time    : 2023/2/27 15:48
@Author  : Eugene
@FileName: 24.龟兔赛跑预测.py 
"""


def main():
    v1, v2, t, s, l = map(int, input().split())
    cnt_time: int = 0
    lt: int = 0
    lr: int = 0
    is_resting: bool = False
    break_time: int = 0
    while (lt < l and lr < l):
        if (is_resting == False and lr - lt < t or is_resting == True and breaktime >= s):
            # 若兔子没在休息, 且与乌龟的距离 < t
            # 或兔子正在休息, 且休息时间够了
            # 则奔跑
            lr = lr + v1
            is_resting = False
            breaktime = 0
        else:
            is_resting = True
            breaktime += 1
        lt = lt + v2
        cnt_time += 1

    if (lt >= l and lr < l):
        print('T')
    elif (lt < l and lr >= l):
        print('R')
    else:
        print('D')
    print(cnt_time)


main()
