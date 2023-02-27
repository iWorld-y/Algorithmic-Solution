def main():
    n = int(input())
    rangeN = range(n)
    nums = []
    chonghao = 0
    duanhao = 0
    check_chong_hao = True
    check_duan_hao = True
    for i in rangeN:
        for num in list(map(int, input().split())):
            nums.append(num)
    nums = sorted(nums)
    for i in rangeN:
        if (check_chong_hao and nums[i] == nums[i + 1]):
            chonghao = nums[i]
            check_chong_hao = False
        elif (check_duan_hao and nums[i] + 1 != nums[i + 1]):
            duanhao = nums[i] + 1
            check_duan_hao = False
        elif (not check_duan_hao and not check_chong_hao):
            break
    print(f"{duanhao} {chonghao}")


# def main():
#     n = int(input())
#     nums = set()
#     chonghao = 0
#     duanhao = 0
#     check_chong_hao = True
#     for i in range(n):
#         line: list = input().split()
#         for j in line:
#             size = len(nums)
#             temp = int(j)
#             nums.add(temp)
#             if (check_chong_hao and size == len(nums)):
#                 chonghao = temp
#                 check_chong_hao = False
#     duanhao = nums.pop()
#     while (nums):
#         temp = nums.pop()
#         if (duanhao + 1 != temp):
#             print(duanhao + 1,end=" ")
#             break
#         duanhao = temp
#     print(chonghao)


main()
