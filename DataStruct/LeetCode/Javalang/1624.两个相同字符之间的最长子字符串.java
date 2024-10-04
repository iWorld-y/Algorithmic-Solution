/*
 * @lc app=leetcode.cn id=1624 lang=java
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start
class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int ans = -1;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            for (int j = len - 1; j > i; j--) {
                if (s.charAt(i) == s.charAt(j)) {
                    ans = Math.max(ans, j - i - 1);
                }
            }
        }
        return ans;
    }
}
// @lc code=end
