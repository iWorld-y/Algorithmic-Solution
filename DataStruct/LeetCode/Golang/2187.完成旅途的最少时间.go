package LeetCode

func minimumTime(time []int, totalTrips int) int64 {
	var l, r = 1, 0
	for _, t := range time {
		if t > r {
			r = t
		}
	}
	r *= totalTrips
	check := func(t int) bool {
		var cnt int64 = 0
		for _, period := range time {
			cnt += int64(t / period)
			if cnt >= int64(totalTrips) {
				return true
			}
		}
		return false
	}
	for l < r {
		mid := l + (r-l)/2
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return int64(l)
}
