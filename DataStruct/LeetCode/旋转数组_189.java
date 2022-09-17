package leetcode;

import java.util.Arrays;

public class 旋转数组_189 {
    public static void main(String[] args) {
        rotate r = new rotate();
        int[] nums = new int[]{1, 2, 3, 4, 5, 6, 7};
        r.rotate(nums, 3);
        System.out.println(Arrays.toString(nums));
    }
}

class rotate {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        k = k % len;
        for (int cnt = 0; cnt < len; cnt++) {
            int temp = nums[cnt];
            nums[cnt] = nums[(cnt + k) % len];
            nums[(cnt + k) % len] = temp;
        }
    }
}