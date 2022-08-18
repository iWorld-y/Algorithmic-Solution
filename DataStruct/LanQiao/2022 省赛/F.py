def main():
    stamp = int(input())
    stamp = int(stamp / 1000)
    h = int(stamp / 3600)
    stamp -= h * 3600
    print(f"stamp:{stamp % 60}")
    m = int(stamp / 60)
    s = stamp - m * 60
    print(f"{h % 60:0>2d}:{m:0>2d}:{s:0>2d}")


if __name__ == '__main__':
    main()
