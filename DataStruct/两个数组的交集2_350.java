package 力扣;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 两个数组的交集2_350 {
    public static void main(String[] args) {
        intersect i = new intersect();
        System.out.println(Arrays.toString(i.intersect(new int[]{4, 9, 5}, new int[]{9, 4, 9, 8, 4})));
    }
}


class intersect {
    public int[] findTheIntersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int len1 = nums1.length, len2 = nums2.length;
        int[] ans2 = new int[len1];
        int cnt = 0;
        for (int ptr1 = 0, ptr2 = 0; ptr1 < nums1.length && ptr2 < nums2.length; ) {
            if (nums1[ptr1] < nums2[ptr2]) {
                ptr1++;
            } else if (nums1[ptr1] > nums2[ptr2]) {
                ptr2++;
            } else if (nums1[ptr1] == nums2[ptr2]) {
                ans2[cnt++] = nums1[ptr1];
                ptr1++;
                ptr2++;
            }
        }

        return Arrays.copyOfRange(ans2, 0, cnt);
    }

    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums1.length <= nums2.length) {
            return findTheIntersection(nums1, nums2);
        } else {
            return findTheIntersection(nums2, nums1);
        }
    }
}