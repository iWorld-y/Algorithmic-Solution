/*
 * @lc app=leetcode.cn id=1598 lang=java
 *
 * [1598] 文件夹操作日志搜集器
 */

// @lc code=start
class Solution {
    public int minOperations(String[] logs) {
        int ans = 0;
        for (String log : logs) {
            if (log.equals("../"))
                ans = Math.max(0, ans - 1);
            else if (log.equals("./"))
                continue;
            else
                ans++;
        }
        return ans;
    }
}

// @lc code=end
