package LeetCode

/*
 * @lc app=leetcode.cn id=860 lang=golang
 *
 * [860] 柠檬水找零
 */

// @lc code=start
func lemonadeChange(bills []int) bool {
	var cnt5, cnt10 uint32 = 0, 0
	for _, v := range bills {
		switch v {
		case 5:
			cnt5++
		case 10:
			cnt10++
			if cnt5 > 0 {
				cnt5--
			} else {
				return false
			}
		case 20:
			if cnt10 > 0 {
				if cnt5 <= 0 {
					return false
				}
				cnt10--
				cnt5--
			} else {
				if cnt5 < 3 {
					return false
				}
				cnt5 -= 3
			}
		}
	}
	return true
}

// @lc code=end
