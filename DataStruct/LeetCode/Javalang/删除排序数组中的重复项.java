package leetcode;

public class 删除排序数组中的重复项 {
    public static void main(String[] args) {
        int[] nums = new int[]{-3, -1, 0, 0, 0, 3, 3};
        removeDuplicates r = new removeDuplicates();
        int limit = r.removeDuplicates(nums);
        System.out.println(limit);
        for (int i = 0; i < limit; i++) {
            System.out.println(nums[i]);
        }
    }
}

class removeDuplicates {

    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return len;
        }
        int fast = 1, slow = 1;
        for (; fast < len; fast++) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }

    // 笨办法
    /*
    public int removeDuplicates(int[] nums) {
        Set<Integer> set = new TreeSet<Integer>();
        int len = 0, j = 0;
        for (int i = 0; i < nums.length; i++) {
            set.add(nums[i]);
        }
        len = set.size();
        for (int num : set) {
            nums[j++] = num;
        }
        return len;
    }
    */
}