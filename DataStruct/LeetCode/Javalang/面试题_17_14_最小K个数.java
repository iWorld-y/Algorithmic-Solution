package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 面试题_17_14_最小K个数 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] arr = solution.smallestK(new int[]{1, 3, 5, 7, 2, 4, 6, 8}, 4);
        System.out.println(Arrays.toString(arr));
    }
}

class Solution {
    public int[] smallestK(int[] arr, int k) {
        List<Integer> ans = new ArrayList<Integer>();
        Arrays.sort(arr);
        for (int i = 0; i < k; i++) {
            ans.add(arr[i]);
        }
        int[] ans_ = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            ans_[i] = ans.get(i);
        }
        return ans_;
    }
}