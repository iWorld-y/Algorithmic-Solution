package leetcode;

import java.util.*;

public class 两数之和_1 {
    public static void main(String[] args) {
        SumOfTwoNumbers solution = new SumOfTwoNumbers();
        int[] arr = solution.twoSum(new int[]{3,3}, 6);
        System.out.println(Arrays.toString(arr));
    }
}

class SumOfTwoNumbers {
    public int[] twoSum(int[] nums, int target) {
        //value:index
        Map<Integer, Integer> map = new HashMap();
        int[] ans = new int[2];
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                ans[0] = i;
                ans[1] = map.get(target - nums[i]);
            }
        }
        Arrays.sort(ans);
        return ans;
    }
}