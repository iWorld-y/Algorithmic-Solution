import os


def getCMake(filePath):
    g = os.walk(rf"D:\Code\LeetCode\DataStruct\{filePath}")
    for path, dir_list, file_list in g:
        for file_name in file_list:
            if (file_name.split(".")[-1] in ["c", "cc", "cpp"]):
                if (len(file_name.split(' ')) != 1):
                    print(f'"DataStruct/{filePath}/{file_name}"')
                else:
                    print(f"DataStruct/{filePath}/{file_name}")


getCMake(r"LeetCode")
getCMake(r"LanQiao")
