package 力扣;

import java.util.*;

public class 数组串联_1929 {
    public static void main(String[] args) {
        Solution4 solution4 = new Solution4();
        System.out.println(Arrays.toString(solution4.getConcatenation(new int[]{1, 2, 1})));
    }
}

class Solution4 {
    public int[] getConcatenation(int[] nums) {
        int len = nums.length;
        int[] ans = new int[len * 2];
        for (int i = 0; i < len; i++) {
            ans[i] = nums[i];
            ans[i + len] = nums[i];
        }
        return ans;
    }
}