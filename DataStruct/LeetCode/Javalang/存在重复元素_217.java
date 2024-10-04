package leetcode;

import java.util.*;

public class 存在重复元素_217 {
    public static void main(String[] args) {
        Exist exist = new Exist();
        System.out.println(exist.containsDuplicate(new int[]{1, 2, 3, 1}));
    }
}

class Exist {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (!set.add(num)) {
                return true;
            }
        }
        return false;
    }
}