/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
class Solution {
   public:
    bool isPowerOfThree(int n) { return n > 0 and 1162261467 % n == 0; }
};
// @lc code=end
