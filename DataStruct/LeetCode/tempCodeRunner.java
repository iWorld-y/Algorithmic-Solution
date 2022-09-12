import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1608 lang=java
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start
class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] >= i && (i == n || nums[i] < i)) {
                return i;
            }
        }
        return -1;
    }
}

// @lc code=end
public class tempCodeRunner {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.specialArray(new int[] { 3, 5 }));
        System.out.println(s.specialArray(new int[] { 0, 4, 3, 0, 4 }));
    }
}